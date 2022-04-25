#pragma once
#include "Simulator.h"
#include "Buffer.h"
#include "random.h"
#include <iostream>
 
#ifndef CAMERA
#define CAMERA
class Camera {
	char id;
	Simulator* messages;
	Buffer* buf;
	bool isActive;
	int indexOfMessages;
public:
	Camera(char tz);

	void generate();

	void sendToBuffer();

	void run();

	void stop();
};

#endif // !CAMERA


