#include "Camera.h"


Camera::Camera() {
	this->id = ++idCameras;
	this->isActive = true;
	this->messages = (BaseMessage**)malloc(sizeof(BaseMessage*));
	this->indexMessages = 0;
	this->buf = new Buffer();
}

Camera::~Camera() {
	for (int i = 0; i < this->indexMessages; i++)
	{
		free(messages[i]);
	}
	messages = NULL;
}

void Camera::generate() {
	int count = getProb(1, 6);
	while (count--) {
		int id = indexMessages + 1;
		int type = getProb(1, 3);
		BaseMessage* newMessage;
		if (type == 2) {
			float distance = getProb(500, 10000);
			float angle = getProb(0, 360);
			float speed = getProb(0, 1000);
			newMessage = new DiscoveryMessage(id, distance, angle, speed);
		}
		else {
			short stat = getProb(1,5);
			newMessage = new StatusMessage(id, stat);
		}

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
	std::cout << "cameraId: " << this->id << "isActive = false\n";
	isActive = false;
	closesocket(this->connection);
	WSACleanup();
}

void Camera::sendServer(char* bufToSend) {
	this->buf->m.lock();
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}

	string getInput = "";
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(80);
	addr.sin_family = AF_INET;

	this->connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(this->connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		
		send(this->connection, *(this->buf->buffer), 14, 0);
		cout << "Buffer sent!" << endl;
		this->buf->m.unlock();
		this->buf->cleanBuffer();

		Sleep(1);
		cout << "Socket closed." << endl << endl;
		std::cout << "camera number: " << (this->id) << "  send . . . ";
		for (int i = 0; i < indexMessages; i++)
		{
			this->messages[i]->print();
		}
	}
	else {
		cout << "Error Connecting to Host" << endl;
		return;
	}

}


void Camera::print() {
	for (int j = 0; j < this->buf->i; j++)
	{
		std::cout << "the buffer in camera:\t" << (this->buf->buffer[j]) << std::endl;
	}
}