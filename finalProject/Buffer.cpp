#include "Buffer.h"

Buffer::Buffer() {
	buffer = (char**)malloc(sizeof(char*));
	i = 1;
}

void Buffer::addToBuffer(char* message) {
	char** tmpBuffer = (char**)realloc(buffer, i * sizeof(char*));
	if (tmpBuffer != NULL) {
		buffer = tmpBuffer;
		buffer[i - 1] = message;
	}
	i++;
}

char** Buffer::getBuffer() {
	return buffer;
}

void Buffer::cleanBuffer() {
	free(buffer);
	buffer = 0;
	i = 0;
}
