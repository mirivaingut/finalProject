#pragma once

#ifndef CAMERA
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CAMERA
#include "Buffer.h"
#include "random.h"
#include "message.h"

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
	BaseMessage** messages;
	Buffer* buf;
	SOCKET connection;
	bool isActive;
	int indexMessages;

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


