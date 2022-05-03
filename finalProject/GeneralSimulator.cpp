#include "GeneralSimulator.h"

GeneralSimulator::~GeneralSimulator() {
	delete[]stopThreadArr;
	delete[]runThreadsArr;
	delete[]sendThreadsArr;
}

GeneralSimulator::GeneralSimulator() {
	sendThreadsArr = new thread[sumC];
	runThreadsArr = new thread[sumC];
	stopThreadArr = new thread[sumC];
}

void GeneralSimulator::sendToServer(Camera* c) {
	while (true) {
		while (c->isActive)
		{
			for (int k = 0; k < c->buf->i; k++)
			{
				c->sendServer(c->buf->buffer[k]);
				std::this_thread::sleep_for(1s);
			}

			//for (int j = 0; j < ms; j++)
			//{
			//	
			//}
		}
	}
}

void GeneralSimulator::runThreads()
{
	/*thread* sendThreadsArr = new thread[sumC];
	thread* runThreadsArr = new thread[sumC];
	thread* stopThreadArr = new thread[sumC];*/

	/*vector<thread> sendThreadsArr(sumC);
	vector<thread> runThreadsArr(sumC);
	vector<thread> stopThreadArr(sumC);*/
	/*std::vector<thread> threads(n);
	std::vector<thread> threads2(n);*/

	for (int i = 0; i < sumC; i++) {
		runThreadsArr[i] = thread(&Camera::run, &cameraArr[i]);
		sendThreadsArr[i] = thread(&GeneralSimulator::sendToServer, this, &cameraArr[i]);
	}

	for (int j = 0; j < sumC; j++) {
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, &cameraArr[j]);
	}


}

