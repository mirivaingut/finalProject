#include "GeneralSimulator.h"
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


#include <thread>
#include <iostream>
#include <vector>
#include "Camera.h"

const int sumCamera = 2;

//Camera arrCamera[sumCamera];
using namespace std;

void runSimulator(Camera c) {
	c.run();
}
void stopSimulator(Camera c) {
	c.stop();

}

void sendToServer(Camera c) {
	while (true) {
		c.send();
		for (int j = 0; j < ms; j++)
		{
			std::this_thread::sleep_for(1s);
		}
	}
}

/**
 * Spawns n threads
 */
void GeneralSimulator::spawnThreads(int n)
{
	int sumOfCameras = n;
	thread* sendThreadsArr = new thread[sumOfCameras];
	thread* runThreadsArr = new thread[sumOfCameras];
	thread* stopThreadArr = new thread[sumOfCameras];
	/*vector<thread> sendThreadsArr(sumOfCameras);
	vector<thread> runThreadsArr(sumOfCameras);
	vector<thread> stopThreadArr(sumOfCameras);*/
	/*std::vector<thread> threads(n);
	std::vector<thread> threads2(n);*/
	// spawn n threads:
	for (int i = 0; i < n; i++) {

		sendThreadsArr[i] = thread(&Camera::send, &cameraArr[i]);
		runThreadsArr[i] = thread(&Camera::run, &cameraArr[i]);
	}

	for (int j = 0; j < sumOfCameras; j++)
	{
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, &cameraArr[j]);
	}

	for (int i = 0; i < sumOfCameras; i++) {
		sendThreadsArr[i].join();
		runThreadsArr[i].join();
		stopThreadArr[i].join();
	}
}

int main()
{
	GeneralSimulator g;
	g.spawnThreads(2);
}
