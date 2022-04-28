//#include "GeneralSimulator.h"
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

Camera arrCamera[sumCamera];
using namespace std;

void runSimulator(int i) {
	arrCamera[i].run();
}
void stopSimulator(int i) {
	arrCamera[i].stop();

}
/**
 * Spawns n threads
 */
void spawnThreads(int n)
{
	std::vector<thread> threads(n);
	// spawn n threads:
	for (int i = 0; i < n; i++) {
		threads[i] = thread(runSimulator, i + 1);
		//threads[i] = thread(stopSimulator, i + 1);
	}

	for (auto& th : threads) {
		th.join();
	}
}

int main()
{
	spawnThreads(2);
	getchar();
}
