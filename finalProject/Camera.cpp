#include "Camera.h"


Camera::Camera(char tz) {
	this->id = tz;
	this->isActive = true;
	this->messages = new Simulator();
}

void Camera::generate() {
	int count = getProb(1, 6);
	int type;
	short status;
	float speed;
	float angle;
	float dis;
	for (int j = 0; j < count; j++)
	{
		type = getProb(1, 3);
		if (type == 1) {
			messages->createStatusMessage();
			indexOfMessages++;
		}
		else {
			dis = getProb(500, 10001);
			angle = getProb(0, 361);
			speed = getProb(0, 1001);
			messages->createDetectionMessage(dis, angle, speed);
			indexOfMessages++;
		}
	}
}

void Camera::sendToBuffer() {
	for (int j = 0; j < indexOfMessages; j++) {
		messages->generateAndSendMessage(j);
	}
	free(messages);
	messages = NULL;
}

void Camera::run() {
	while (isActive) {
		generate();
		if (isActive) {
			sendToBuffer();
		}
	}
}

void Camera::stop() {
	isActive = false;
}
