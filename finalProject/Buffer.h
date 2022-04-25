#pragma once
#include <iostream>

#ifndef BUFFER
#define BUFFER

class Buffer {
	char** buffer;
	int i = 1;

public:
	void addToBuffer(char* message);

	char** getBuffer();

	void cleanBuffer();
};

#endif // !BUFFER

