#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <list>
#include <process.h>

#pragma comment(lib,"ws2_32.lib") 

struct IoData
{
	IoData()
	{
		ZeroMemory(this,sizeof(IoData));
	}

	OVERLAPPED OverL;
	CHAR buffer[1024];
	BYTE Type;
	DWORD Len;
	WSABUF wsabuffer;
};

class FClient
{
public:
	FClient(SOCKET S, SOCKADDR_IN InSin);
	virtual ~FClient(){}

	BOOL Recv();
	BOOL Send();

public:
	SOCKET ClientSokcet;
	SOCKADDR_IN Sin;
	IoData Data;
};

FClient::FClient(SOCKET S, SOCKADDR_IN InSin)
	:ClientSokcet(S)
	,Sin(InSin)
{

}

BOOL FClient::Recv()
{
	DWORD Flag = 0;
	DWORD Len = 0;
	Data.Type = 0;
	Data.wsabuffer.buf = Data.buffer;
	Data.wsabuffer.len = 1024;
	if (WSARecv(ClientSokcet,
		&Data.wsabuffer,
		1,
		&Len,&Flag,&Data.OverL,NULL) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != ERROR_IO_PENDING)//GetOverlappedResult
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL FClient::Send()
{
	DWORD Flag = 0L;
	DWORD Len = 0L;
	Data.Type = 1;
	Data.wsabuffer.buf = Data.buffer;
	Data.wsabuffer.len = strlen(Data.buffer);
	if (WSASend(ClientSokcet,
		&Data.wsabuffer,
		1,
		&Len, Flag, (LPOVERLAPPED)&Data.OverL, NULL) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != ERROR_IO_PENDING)//GetOverlappedResult
		{
			return FALSE;
		}
	}

	return TRUE;
}

std::list<FClient*> ClientList;

void ListRemove(FClient *C)
{
	for (std::list<FClient*>::iterator iter = ClientList.begin();iter != ClientList.end();++iter)
	{
		if (C == (*iter))
		{
			ClientList.erase(iter);
			break;
		}
	}
}

HANDLE Cp = NULL;
unsigned int __stdcall Run(void* Content)
{
	for (;;)
	{
		Sleep(1000);
		DWORD IOSize = -1;
		LPOVERLAPPED lpOverlapped = NULL;
		FClient* Client = NULL;

		bool Ret = GetQueuedCompletionStatus(Cp, &IOSize, (LPDWORD)&Client, &lpOverlapped, INFINITE);
		if (Client == NULL && lpOverlapped == NULL)
		{
			break;
		}

		if (Ret)
		{
			if (IOSize == 0)
			{
				ListRemove(Client);
				continue;
			}

			IoData* pData = CONTAINING_RECORD(lpOverlapped, IoData, OverL);
			switch (pData->Type)
			{
				case 0://���� �ͻ��˷��͵���Ϣ
				{
					Client->Data.Len = IOSize;
					Client->Data.buffer[IOSize] = '\0';
					printf(Client->Data.buffer);

					char buffer[1024] = { 0 };

					sprintf_s(buffer, 1024, "hi I ma Server (%d)", Client->ClientSokcet);
					strcpy(Client->Data.buffer, buffer);
					Client->Send();
					break;
				}
				
				case 1://����
				{
					printf(Client->Data.buffer);
					Client->Data.Len = 0;
					if (!Client->Recv())
					{
						ListRemove(Client);
					}

					break;
				}
			}
		}
		else
		{
			DWORD Msg = GetLastError();
			if (Msg == WAIT_TIMEOUT)
			{
				continue;
			}
			else if (lpOverlapped != NULL)
			{
				ListRemove(Client);
			}
			else
			{
				break;
			}
		}
	}

	return 0;
}

int main()
{
	//�̵߳ķ��ؾ��
	HANDLE hThreadHandle[32];

	if ((Cp = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE,//�򿪵��ļ����
		NULL,//
		0,
		0)) == NULL)
	{
		//GetLastError();
		printf("������ɶ˿�ʧ�� ~~ \n");
		return -1;
	}
	SYSTEM_INFO SystemInfo;
	GetSystemInfo(&SystemInfo);
	DWORD CPUNumber = SystemInfo.dwNumberOfProcessors;//CPU����

	for (int i =0 ;i < CPUNumber * 2 ;i++)
	{
		hThreadHandle[i] = (HANDLE)_beginthreadex(
			NULL,// ��ȫ���ԣ� ΪNULLʱ��ʾĬ�ϰ�ȫ��
			0,// �̵߳Ķ�ջ��С�� һ��Ĭ��Ϊ0
			Run, // ��Ҫ�������̺߳���
			Cp, // �̺߳����Ĳ����� ��һ��void*���ͣ� ���ݶ������ʱ�ýṹ��
			0,// ���̵߳ĳ�ʼ״̬��0��ʾ����ִ�У�CREATE_SUSPENDED��ʾ����֮�����
			NULL);   // ���������߳�ID
	}

	WSADATA WsaData;
	int Ret = 0;
	if ((Ret = WSAStartup(MAKEWORD(2, 1), &WsaData)) != 0)
	{
		return -1;
	}

	//����Socket
	SOCKET Listen = INVALID_SOCKET;
	if ((Listen = WSASocket(
		AF_INET,//
		SOCK_STREAM, //TCP  SOCK_DGRAM
		0, //Э��
		NULL,//
		0, 
		WSA_FLAG_OVERLAPPED//
		)) == INVALID_SOCKET)
	{
		WSACleanup();
		return -1;
	}
	SOCKADDR_IN Sin;
	Sin.sin_family = AF_INET;//IPV4������Э����
	Sin.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//0.0.0.0 ���Ե�ַ��
	Sin.sin_port = htons(98592);

	if (bind(Listen, (SOCKADDR*)&Sin,sizeof(Sin)) == SOCKET_ERROR)
	{
		closesocket(Listen);
		WSACleanup();
		return -1;
	}

	if (listen(Listen, SOMAXCONN))
	{
		closesocket(Listen);
		WSACleanup();
		return -1;
	}

	//iocp��Ͷ��
	SOCKET ClientAccept = INVALID_SOCKET;
	SOCKADDR_IN ClientAddr;
	int ClientAddrLen = sizeof(ClientAddr);

	// ������û�пͻ�������
	for (;;)
	{
		if ((ClientAccept = WSAAccept(//��������
			Listen,
			(SOCKADDR*)&ClientAddr,
			&ClientAddrLen,
			NULL,
			0))== SOCKET_ERROR)
		{
			break;
		}
		FClient *InClient = new FClient(ClientAccept, ClientAddr);
		ClientList.push_back(InClient);

		//����ɶ˿�
		if (CreateIoCompletionPort(
			(HANDLE)ClientAccept,
			Cp, 
			(DWORD)InClient,0) == NULL)
		{
			break;
		}

		if (!InClient->Recv())
		{
			ListRemove(InClient);
		}
	}

	//�����̳߳�
	for (int i = 0; i < CPUNumber * 2; i++)
	{
		PostQueuedCompletionStatus(Cp, 0, NULL, NULL);
		CloseHandle(hThreadHandle[i]);
	}

	WaitForMultipleObjects(CPUNumber * 2, hThreadHandle, TRUE, INFINITE);

	return 0;
}