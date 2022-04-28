#pragma once
#include "Simulator.h"
#include "Buffer.h"
#include "random.h"
#include <iostream>
#include "message.h"
static int idCameras=0;

#ifndef CAMERA
#define CAMERA
class Camera {
public:
	char id;
	BaseMessage** messages/*=(BaseMessage**)malloc(sizeof(BaseMessage*))*/;
	/*Simulator* messages;*/
	Buffer* buf;
	bool isActive;
	int indexMessages;

	Camera();
	void generate();
	void sendToBuffer();
	void run();
	void stop();
	void sendToServer(Camera c);
	void send();
	void print();
};

#endif // !CAMERA


