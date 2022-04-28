#include "GeneralSimulator.h"

//const int sumCamera = 2;
//
//void GeneralSimulator::runSimulator(int i) {
//	cameraArr[i].run();
//}
//
//void GeneralSimulator::stopSimulator(int i) {
//	cameraArr[i].stop();
//}
//
//void GeneralSimulator::sendToServer(int i) {
//	while (true) {
//		cameraArr[i].send();
//		for (int j = 0; j < ms; j++)
//		{
//			std::this_thread::sleep_for(1s);
//		}
//	}
//}
//
//void GeneralSimulator::runGeneralSimulator() {
//	vector<thread> sendThreadsArr(sumOfCameras);
//	vector<thread> runThreadsArr(sumOfCameras);
//	vector<thread> stopThreadArr(sumOfCameras);
//	for (int i = 0; i < sumOfCameras; i++)
//	{
//		cout << "מצלמה מספר: " << i << "\nלעצירה הקש על תו כלשהוא." << endl;
//		sendThreadsArr[i] = thread(&GeneralSimulator::sendToServer, i);
//		runThreadsArr[i] = thread(&GeneralSimulator::runSimulator, i);
//		/*std::thread	sendth(&GeneralSimulator::sendToServer, i);
//		std::thread	runth(&GeneralSimulator::runSimulator, i);*/
//	}
//
//	for (int j = 0; j < sumOfCameras; j++)
//	{
//		getchar();
//		stopThreadArr[j] = thread(&GeneralSimulator::stopSimulator, j);
//		//std::thread	stopth(&GeneralSimulator::stopSimulator, j);
//	}
//
//}

//void runSimulator(Camera c) {
//	c.run();
//}
//void stopSimulator(Camera c) {
//	c.stop();
//
//}
//
//GeneralSimulator::~GeneralSimulator() {
//	delete []cameraArr;
//}

GeneralSimulator::~GeneralSimulator() {
	delete[]stopThreadArr;
	delete[]runThreadsArr;
	delete[]sendThreadsArr;
}

GeneralSimulator::GeneralSimulator() {
	sendThreadsArr = new thread[sumOfCameras];
	runThreadsArr = new thread[sumOfCameras];
	stopThreadArr = new thread[sumOfCameras];
}

void GeneralSimulator::sendToServer(Camera* c) {
	while (true) {
		while (c->isActive)
		{
			c->send();
			for (int j = 0; j < ms; j++)
			{
				std::this_thread::sleep_for(1s);
			}
		}
	}
}

void GeneralSimulator::runThreads()
{
	/*thread* sendThreadsArr = new thread[sumOfCameras];
	thread* runThreadsArr = new thread[sumOfCameras];
	thread* stopThreadArr = new thread[sumOfCameras];*/

	/*vector<thread> sendThreadsArr(sumOfCameras);
	vector<thread> runThreadsArr(sumOfCameras);
	vector<thread> stopThreadArr(sumOfCameras);*/
	/*std::vector<thread> threads(n);
	std::vector<thread> threads2(n);*/

	for (int i = 0; i < sumOfCameras; i++) {
		sendThreadsArr[i] = thread(&GeneralSimulator::sendToServer, this, &cameraArr[i]);
		runThreadsArr[i] = thread(&Camera::run, &cameraArr[i]);
	}

	for (int j = 0; j < sumOfCameras; j++) {
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, &cameraArr[j]);
	}

	
}

int main()
{
	GeneralSimulator* g=new GeneralSimulator();
	g->runThreads();
	for (int i = 0; i < sumOfCameras; i++) {
		//g->sendThreadsArr[i].join();
		g->runThreadsArr[i].join();
		g->stopThreadArr[i].join();
	}

	for (int i = 0; i < sumOfCameras; i++)
	{
		g->cameraArr[i].print();
		//cout << "the buffer:::::::::::  " << (g->cameraArr[i].buf->buffer)<<endl;
	}
	return 1;
}
