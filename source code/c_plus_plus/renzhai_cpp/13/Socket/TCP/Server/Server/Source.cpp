#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>  

#pragma comment(lib,"ws2_32.lib")   
using namespace std;

#define INDEX_NONE -1

int main()
{
	WSADATA WsaData;
	//1.��ʼ����
	if (WSAStartup(MAKEWORD(4,3),&WsaData) != 0)
	{
		return INDEX_NONE;
	}

	//2.����Socket
	//AF_INET6 
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "����ʧ��" << endl;
		WSACleanup();
		return INDEX_NONE;
	}

	//3.����IP�Ͷ˿�
	sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;//ipv4
	ServerAddr.sin_port = htons(12341);
	ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(ListenSocket,(SOCKADDR*)&ServerAddr,sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		cout << "��ʧ��" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	
	//4.��������
	if (listen(ListenSocket,5) == SOCKET_ERROR)
	{
		cout << "����ʧ��" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}

	sockaddr_in ClientAddr;
	int ClientAddrLen = sizeof(ClientAddr);
	cout << "�ȴ�����..." << endl;

	//5.��������
	SOCKET RevSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLen);
	if (RevSocket == INVALID_SOCKET)
	{
		cout << "�ͻ��˷������� ����˽���ʧ��" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	else
	{
		cout << "�ͻ��˷������� ����˽��ܳɹ�" << endl;
		cout << "�ͻ��˵ĵ�ַ :"<< inet_ntoa(ClientAddr.sin_addr) << endl;
		cout << "�ͻ��˵Ķ˿� :" << ClientAddr.sin_port << endl;
	}

	//6.���ܿͻ�����Ϣ
	char BufferData[1024] = { 0 };
	int Res = recv(RevSocket, BufferData, 1024, 0);
	if (Res == 0)
	{
		cout << "���ӹر�" << endl;
	}
	else if (Res > 0)
	{
		cout << "�ͻ��˷��͵������� ��"<< BufferData << endl;
		cout << "�ͻ��˷��͵����ݵĴ�С�� ��" << Res << endl;
	}
	else
	{
		cout << "����ʧ��: ��" << WSAGetLastError() << endl;
	}

	memset(BufferData, 0, 1024);
	strcpy(BufferData, "Server Hello~");

	send(RevSocket, BufferData,strlen(BufferData),0);

	closesocket(ListenSocket);
	WSACleanup();

	return 0;
}