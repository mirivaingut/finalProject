#include "Buffer.h"

Buffer::Buffer() {
	buffer = (char**)malloc(sizeof(char*));
	i = 1;
}

void Buffer::addToBuffer(char* message) {
	m.lock();
	char** tmpBuffer = (char**)realloc(buffer, i * sizeof(char*));
	if (tmpBuffer != NULL) {
		buffer = tmpBuffer;
		buffer[i - 1] = message;
	}
	i++;
	m.unlock();
}

char** Buffer::getBuffer() {
	m.lock();
	char** bufftmp = buffer;
	return bufftmp;
	m.unlock();
}

void Buffer::cleanBuffer() {
	m.lock();
	free(buffer);
	buffer = 0;
	i = 0;
	m.unlock();
}
