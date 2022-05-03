#pragma once
#include <iostream>
#include <mutex>


#ifndef BUFFER
#define BUFFER


class Buffer {

public:
	std::mutex m;
	char** buffer;
	int i = 1;

	Buffer();
	void addToBuffer(char* message);
	char** getBuffer();
	void cleanBuffer();
};

#endif // !


