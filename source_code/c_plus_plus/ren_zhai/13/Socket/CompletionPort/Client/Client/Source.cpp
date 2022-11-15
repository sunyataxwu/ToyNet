#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib") 

int main()
{
	WSADATA WsaData;
	int Ret = 0;
	if ((Ret = WSAStartup(MAKEWORD(2, 1), &WsaData)) != 0)
	{
		return -1;
	}

	for (;;)
	{
		SOCKET ClientSocket = socket(
			AF_INET,
			SOCK_STREAM,
			IPPROTO_TCP // IPPROTO_IP
		);

		SOCKADDR_IN Sin;
		Sin.sin_family = AF_INET;//IPV4������Э����
		Sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//0.0.0.0 ���Ե�ַ��
		Sin.sin_port = htons(98592);

		if (connect(
			ClientSocket, 
			(SOCKADDR*)&Sin,
			sizeof(Sin)) == SOCKET_ERROR)
		{
			closesocket(ClientSocket);
			break;
		}

		//������
		char buffer[1024] = { 0 };
		sprintf_s(buffer, 1024, "Hello I'am client %d \n",ClientSocket);

		send(ClientSocket, buffer, strlen(buffer), 0);

		memset(buffer, 0, 1024);
		recv(ClientSocket, buffer, sizeof(buffer), 0);//����

		printf(buffer);

		closesocket(ClientSocket);
	}

	WSACleanup();
	return 0;
}

//c����Git