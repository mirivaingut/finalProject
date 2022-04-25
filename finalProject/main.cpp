#include "Buffer.h"
#include "Camera.h"
#include "message.h"
#include "random.h"
#include "Simulator.h"
#include <iostream>

void main() {
	printf("hello");
	Simulator* s = new Simulator();
	s->createStatusMessage();
	s->createDetectionMessage(100.2,23.4,456.9);
	s->createDetectionMessage(100.2, 23.4, 456.9);
	s->generateAndSendMessage(0);
}