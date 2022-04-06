#include <iostream>
#include <string.h>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main()
{
	WSAData WsaData;
	WSAStartup(WINSOCK_VERSION,&WsaData);

	SOCKET SocketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (SocketServer == INVALID_SOCKET)
	{

		WSACleanup();
		return -1;
	}

	//
	sockaddr_in addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(12341);
	addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bool bReuseAddr = true;
	int Ret = setsockopt(SocketServer,SOL_SOCKET,SO_REUSEADDR, (char*)&bReuseAddr,sizeof(bReuseAddr));
	if (Ret == SOCKET_ERROR)
	{

		WSACleanup();
		return -1;
	}

	Ret = bind(SocketServer, (sockaddr*)&addrServer, sizeof(addrServer));
	if (Ret == SOCKET_ERROR)
	{

		WSACleanup();
		return -1;
	}

	Ret = listen(SocketServer, 5);
	if (Ret != 0)
	{
		WSACleanup();
		return -1;
	}

	fd_set _set;
	FD_ZERO(&_set);
	FD_SET(SocketServer,&_set);

	SOCKET ClientSocket;
	sockaddr_in AddrClient;
	int AddrClientLen = sizeof(AddrClient);

	char Buffer[1024] = { 0 };

	//����Ҫ��Select �����ӿͻ���
	while (1)
	{
		//int PASCAL FAR select(
		//	_In_ int nfds,
		//	_Inout_opt_ fd_set FAR * readfds, accept
		//	_Inout_opt_ fd_set FAR * writefds,
		//	_Inout_opt_ fd_set FAR * exceptfds,
		//	_In_opt_  const struct timeval FAR * timeout);
		fd_set Lastfd = _set;
		Ret = select(0,&Lastfd,NULL,NULL,nullptr);
		if (Ret >= 0)
		{
			for (UINT i = 0; i < _set.fd_count;i++)
			{
				if (FD_ISSET(_set.fd_array[i],&Lastfd))
				{
					if (_set.fd_array[i] == SocketServer)//ר�Ŵ��������
					{
						//���������ܲ���
						memset(&AddrClient, 0, AddrClientLen);
						ClientSocket = accept(SocketServer, (sockaddr*)&AddrClient, &AddrClientLen);
						if (ClientSocket != INVALID_SOCKET)
						{
							FD_SET(ClientSocket,&_set);
							cout << "һ���ͻ������ӽ���" << 
								ClientSocket <<"�˿��� ��" 
								<<ntohs(AddrClient.sin_port)<<
								inet_ntoa(AddrClient.sin_addr)<< endl;
						}
					}
					else //���ܿͻ��˵���Ϣ
					{
						//buff����
						memset(Buffer, 0, 1024);
						Ret = recv(_set.fd_array[i], Buffer, 1024, 0);
						if (Ret == 0)//�ͻ��������˳�
						{
							closesocket(_set.fd_array[i]);
							FD_CLR(_set.fd_array[i],&_set);
							cout << "�����˳�" << endl;
							i--;
						}

						if (Ret == SOCKET_ERROR)
						{
							closesocket(_set.fd_array[i]);
							FD_CLR(_set.fd_array[i], &_set);
							cout << "���ܴ���" << endl;
							i--;
						}

						//
						getpeername(_set.fd_array[i], (sockaddr*)&AddrClient,&AddrClientLen);
						if (Ret > 0)
						{
							//����
							cout << "�˿�:" << ntohs(AddrClient.sin_port) << "IP:" <<
								inet_ntoa(AddrClient.sin_addr) << "Buffer = " <<Buffer 
								<< "BufferLen = "<< Ret <<endl;

							memset(Buffer, 0, 1024);
							strcpy(Buffer, "Hi Server");
							Ret = send(_set.fd_array[i], Buffer, strlen(Buffer), 0);
							if (Ret == SOCKET_ERROR)
							{
								cout << "����ʧ��" << endl;
								closesocket(_set.fd_array[i]);
							}
						}
					}
				}
			}
		}
		else if (Ret == SOCKET_ERROR)
		{

		}
	}


	return 0;
}