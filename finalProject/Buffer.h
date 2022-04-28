#pragma once
#include <iostream>

#ifndef BUFFER
#define BUFFER

class Buffer {

public:
	char** buffer/*=(char**)malloc(sizeof(char*))*/;
	int i = 1;
	Buffer();
	void addToBuffer(char* message);
	char** getBuffer();
	void cleanBuffer();
};

#endif // !BUFFER

