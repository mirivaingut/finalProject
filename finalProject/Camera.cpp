#include "Camera.h"


Camera::Camera() {
	this->id = ++idCameras;
	this->isActive = true;
	this->messages = (BaseMessage**)malloc(sizeof(BaseMessage*));
	this->indexMessages = 0;
	this->buf = new Buffer();
}

//void Camera::generate() {
//	int count = getProb(1, 6);
//	int type;
//	short status;
//	float speed;
//	float angle;
//	float dis;
//	for (int j = 0; j < count; j++)
//	{
//		type = getProb(1, 3);
//		if (type == 1) {
//			messages->createStatusMessage();
//			indexOfMessages++;
//		}
//		else {
//			dis = getProb(500, 10001);
//			angle = getProb(0, 361);
//			speed = getProb(0, 1001);
//			messages->createDetectionMessage(dis, angle, speed);
//			indexOfMessages++;
//		}
//	}
//}

Camera::~Camera() {
	for (int i = 0; i < this->indexMessages; i++)
	{
		free(messages[i]);
	}
	messages = NULL;
	//free(buf);
}


void Camera::generate() {
	int count = getProb(1, 6);
	//std::cout << "generate camera id= " << id <<", count "<<count<< '\n';
	while (count--) {
		int id = indexMessages + 1;
		float distance = getProb(500, 10000);
		float angle = getProb(0, 360);
		float speed = getProb(0, 1000);
		BaseMessage* newMessage = new DiscoveryMessage(id, distance, angle, speed);
		//std::cout << "index is " << indexMessages << '\n';
		BaseMessage** tmpMassages = (BaseMessage**)realloc(messages, sizeof(BaseMessage*) * (indexMessages + 1));
		int cnt = 0;
		while (tmpMassages == NULL) {
			sendToBuffer();
			tmpMassages = (BaseMessage**)realloc(messages, sizeof(BaseMessage*) * (indexMessages + 1));
			if (cnt++ == 3) {
				std::cout << "I don't have anough place of memory, sory!" << '\n';
				stop();
			}
		}
		messages = tmpMassages;
		this->messages[indexMessages] = newMessage;
		//std::cout << " messages is " ;
		//messages[indexMessages]->print();
		indexMessages++;
	}
}


void Camera::sendToBuffer() {
	for (int j = 0; j < indexMessages; j++) {
		messages[j]->parseBack();
		buf->addToBuffer(reinterpret_cast<char*>(messages[j]->getMessageBuffer()));
		std::cout << "messageId: " << (messages[j]->messageId) << "  messageBuffer: " << (messages[j]->messageBuffer) << "\n";
	}
	free(messages);
	messages = NULL;
	indexMessages = 0;
}

void Camera::run() {
	while (this->isActive) {
		generate();
		if (isActive) {
			sendToBuffer();
		}
	}
}

void Camera::stop() {
	std::cout <<"cameraId: "<<this->id<< "isActive = false\n";
	isActive = false;
}

void Camera::send() {
	//send to server:
	//buf->getBuffer();
	std::cout << "camera number: " << (this->id) << "  send . . . ";
	for (int i = 0; i < indexMessages; i++)
	{
		
		this->messages[i]->print();
	}
}

void Camera::print() {
	for (int j = 0; j < this->buf->i ; j++)
	{
		std::cout << "the buffer in camera:\t"<<(this->buf->buffer[j]) << std::endl;
	}
}