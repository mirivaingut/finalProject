#pragma once
#include <iostream>
#include <mutex>


#ifndef BUFFER
#define BUFFER


class Buffer {

public:
	std::mutex m;
	char** buffer/*=(char**)malloc(sizeof(char*))*/;
	int i = 1;
	Buffer();
	void addToBuffer(char* message);
	char** getBuffer();
	void cleanBuffer();
};

#endif // !BUFFER

