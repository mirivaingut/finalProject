#include "Buffer.h"


void Buffer::addToBuffer(char* message) {
	buffer = (char**)realloc(buffer, i * sizeof(char*));
	buffer[i - 1] = message;
	i++;
}

char** Buffer::getBuffer() {
	return buffer;
}

void Buffer::cleanBuffer() {
	free(buffer);
	buffer = 0;
}
