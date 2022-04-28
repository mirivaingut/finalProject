#pragma once
#include "message.h"
#include <iostream>
#ifndef SIMULATOR
#define SIMULATOR

class Simulator {
public:
	BaseMessage** buffer=(BaseMessage**)malloc(1);
	int i = 1;
	~Simulator();

	void createStatusMessage();

	void createDetectionMessage(float dis, float ang, float spe);

	unsigned char* generateAndSendMessage(int index);

};

#endif // !SIMULATOR
