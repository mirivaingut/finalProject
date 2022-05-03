#pragma once

#ifndef CAMERA
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CAMERA
#include "Simulator.h"
#include "Buffer.h"
#include "random.h"
#include "message.h"

//#include "pch.h"
//#include "afxwin.h"

//#include "stdafx.h"
//#include <unistd.h>
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;
static int idCameras=0;
class Camera {
public:
	char id;
	BaseMessage** messages/*=(BaseMessage**)malloc(sizeof(BaseMessage*))*/;
	Buffer* buf;
	SOCKET connection;
	bool isActive;
	int indexMessages;
	/*Simulator* messages;*/

	Camera();
	~Camera();
	void generate();
	void sendToBuffer();
	void run();
	void stop();
	void sendToServer(Camera c);
	void sendServer(char * bufToSend);
	void print();
};

#endif // !CAMERA


