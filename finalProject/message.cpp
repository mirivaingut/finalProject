#include "message.h"

using namespace std;

BaseMessage::BaseMessage(unsigned char* buffer, int id) {
	//printf("BaseMessage(unsigned char* buffer, int id)\n");
	this->messageBuffer = buffer;
	this->messageId = id;
	messageType = static_cast<int>(messageBuffer[1]);
}

BaseMessage::BaseMessage(int type, int id) {
	//cout << "BaseMessage:" << type << " ,,, " << id << "\n";
	this->messageBuffer = 0;
	this->messageId = id;
	messageType = type;
}

BaseMessage::~BaseMessage() {
	delete[]messageBuffer;
}

void BaseMessage::parseMessage()
{

}

void BaseMessage::parseBack()
{

}

unsigned char* BaseMessage::getMessageBuffer() {
	return messageBuffer;
}

StatusMessage::StatusMessage(unsigned char* buffer, int id) :BaseMessage(buffer, id) {
	//cout << "StatusMessage" << buffer << "  " << id << "\n";
	status = 0;
}

StatusMessage::StatusMessage(int id) : BaseMessage(1, id) {
	//printf("StatusMessage(int id)\n");
	status = 0;
}

void StatusMessage::parseMessage() {
	status = static_cast<short>(messageBuffer[2]);
}

void StatusMessage::parseBack() {
	this->messageBuffer = new unsigned char[3];
	memcpy((void*)(messageBuffer), (void*)(&messageType), 2);
	memcpy((void*)(messageBuffer + 2), (void*)(&status), 1);
}

void StatusMessage::print() {
	//cout << "\tstatus:  " << status << endl;
}

DiscoveryMessage::DiscoveryMessage(unsigned char* buffer, int id) :BaseMessage(buffer, id) {
	//printf("DiscoveryMessage(unsigned char* buffer, int id)\n");
	distance = 0;
	angle = 0;
	speed = 0;
}

DiscoveryMessage::DiscoveryMessage(int id, float dis, float ang,float spe ) :BaseMessage(1, id) {
	//printf("DiscoveryMessage(float distance, float angle, float speed, int id)\n");
	this->distance = dis;
	angle = ang;
	speed = spe;
}

void DiscoveryMessage::parseMessage() {
	memcpy((void*)(&distance), (void*)(messageBuffer[2]), 4);
	memcpy((void*)(&angle), (void*)(messageBuffer[6]), 4);
	memcpy((void*)(&speed), (void*)(messageBuffer[10]), 4);
}

void DiscoveryMessage::parseBack() {
	messageBuffer = new unsigned char[14];
	memcpy((void*)(messageBuffer), (void*)(&messageType), 2);
	memcpy((void*)(messageBuffer + 2), (void*)(&distance), 4);
	memcpy((void*)(messageBuffer + 6), (void*)(&angle), 4);
	memcpy((void*)(messageBuffer + 10), (void*)(&speed), 4);
}

void DiscoveryMessage::print() {
	cout << "distance:  " << distance << endl
		<< "angle:  " << angle << endl
		<< "speed:  " << speed << endl;
}
