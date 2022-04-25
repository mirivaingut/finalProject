#pragma once
#include "message.h"
#include <iostream>
#ifndef SIMULATOR
#define SIMULATOR

class Simulator {
	BaseMessage** buffer;
	int i = 1;
public:
	~Simulator();

	void createStatusMessage();

	void createDetectionMessage(float dis, float ang, float spe);

	unsigned char* generateAndSendMessage(int index);
};

#endif // !SIMULATOR
