//#include "GeneralSimulator.h"
//#include "Global.h"

//
//int main()
//{
//	GeneralSimulator* g = new GeneralSimulator();
//	g->runThreads();
//	for (int i = 0; i < sumOfCameras; i++) {
//		//g->sendThreadsArr[i].join();
//		g->runThreadsArr[i].join();
//		g->stopThreadArr[i].join();
//	}
//
//	for (int i = 0; i < sumOfCameras; i++)
//	{
//		g->cameraArr[i].print();
//		//cout << "the buffer:::::::::::  " << (g->cameraArr[i].buf->buffer)<<endl;
//	}
//	return 1;
//}

//#include "pch.h"
//#include "afxwin.h"

//#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
//#include <unistd.h>
using namespace std;


int main()
{
	string buf = "000242c8a4194389c00042b16666";
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}

	string getInput = "";
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(80);
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		cout << "sin_port: " << addr.sin_port << endl;
		cout << "sin_family: " << addr.sin_family << endl;
		cout << "sin_zero: " << addr.sin_zero << endl;
		//cout << "sin_addr.S_un: " << addr.sin_addr.S_un << endl;

		getline(cin, getInput);
		//send(connection, "pshshhshs", 2, 0);
		send(connection, buf.c_str(), buf.length(), 0);
		cout << "Message sent!" << endl;
		closesocket(connection);
		WSACleanup();
		cout << "Socket closed." << endl << endl;
		exit(0);
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
	return 0;
}