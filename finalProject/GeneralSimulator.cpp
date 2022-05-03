#include "GeneralSimulator.h"

GeneralSimulator::~GeneralSimulator() {
	delete[]stopThreadArr;
	delete[]runThreadsArr;
	delete[]sendThreadsArr;
}

void GeneralSimulator::config() {
	fstream newfile;
	int f, l;

	newfile.open("conf.txt", ios::in);

	if (newfile.is_open()) {
		string tp;
		getline(newfile, tp);
		f = tp.find(':');
		l = tp.find('.');
		sumOfCameras = stoi(tp.substr(f + 1, l - (f + 1)));
		cout << "sumOfCameras:  " << sumOfCameras << endl;
		getline(newfile, tp);
		f = tp.find(':');
		l = tp.find('.');
		ms = stoi(tp.substr(f + 1, l - (f + 1)));
		cout << "ms:  " << ms << endl;
	}
}


int GeneralSimulator::getSumOfCameras() {
	return sumOfCameras;
}

int GeneralSimulator::getMs() {
	return ms;
}

GeneralSimulator::GeneralSimulator() {
	config();
	cameraArr = new Camera[getSumOfCameras()];
	sendThreadsArr = new thread[getSumOfCameras()];
	runThreadsArr = new thread[getSumOfCameras()];
	stopThreadArr = new thread[getSumOfCameras()];
}

void GeneralSimulator::sendToServer(Camera* c) {
	while (c->isActive)
	{
		for (int k = 0; k < c->buf->i; k++)
		{
			c->sendServer(c->buf->buffer[k]);
		}
		for (int j = 0; j < getMs(); j++)
		{
			std::this_thread::sleep_for(1s);
		}
	}
}

void GeneralSimulator::runThreads()
{
	for (int i = 0; i < getSumOfCameras(); i++) {
		runThreadsArr[i] = thread(&Camera::run, &cameraArr[i]);
		sendThreadsArr[i] = thread(&GeneralSimulator::sendToServer, this, &cameraArr[i]);
	}

	for (int j = 0; j < getSumOfCameras(); j++) {
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, &cameraArr[j]);
	}

	for (int i = 0; i < getSumOfCameras(); i++) {
		sendThreadsArr[i].join();
		runThreadsArr[i].join();
		stopThreadArr[i].join();
	}
}


