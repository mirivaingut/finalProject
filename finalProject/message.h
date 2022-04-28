#pragma once
#include <iostream>
#include <random>

#ifndef MESSAGE
#define MESSAGE

class BaseMessage
{
public:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
	BaseMessage(unsigned char* buffer, int id);

	BaseMessage(int type, int id);

	~BaseMessage();

	virtual void parseMessage()=0;
	virtual void parseBack()=0;
	virtual void print()=0;
	unsigned char* getMessageBuffer();
};

class StatusMessage :public BaseMessage {
protected:
	short status;
public:
	StatusMessage(unsigned char* buffer, int id) ;

	StatusMessage(int id);

	virtual void parseMessage();

	virtual void parseBack();
	virtual void print();
};

class DiscoveryMessage :public BaseMessage {
protected:
	float distance;
	float angle;
	float speed;

public:
	DiscoveryMessage(unsigned char* buffer, int id);

	DiscoveryMessage(int id, float dis, float ang, float spe);

	virtual void parseMessage();

	virtual void parseBack();

	virtual void print();
};

#endif // !MESSAGE

