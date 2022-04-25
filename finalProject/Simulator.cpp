#include "Simulator.h"


using namespace std;

Simulator::~Simulator() {
	for (int j = 0; j < i; j++)
	{
		delete (buffer + j);
	}
	delete[]buffer;
}

void Simulator::createStatusMessage() {
	buffer = (BaseMessage**)realloc(buffer, i * sizeof(BaseMessage*));
	buffer[i - 1] = new StatusMessage(i);
	i++;
}

void Simulator::createDetectionMessage(float dis, float ang, float spe) {
	buffer = (BaseMessage**)realloc(buffer, i * sizeof(BaseMessage*));
	buffer[i - 1] = new DiscoveryMessage(dis, ang, spe, i);
	i++;
}

unsigned char* Simulator::generateAndSendMessage(int index) {
	buffer[index]->print();
	buffer[index]->parseBack();
	cout << "\n-------------------\nparseback. . . \n-------------------\n";
	buffer[index]->print();
	return buffer[index]->getMessageBuffer();
}

