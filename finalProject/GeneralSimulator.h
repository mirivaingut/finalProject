#pragma once
#include "Camera.h"
#include <iostream>
#include <thread>
#include <vector>
#ifndef generalSIMULATOR
#define generalSIMULATOR

using namespace std::literals::chrono_literals;
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class GeneralSimulator
{
public:

	Camera* cameraArr;
	thread* sendThreadsArr;
	thread* runThreadsArr;
	thread* stopThreadArr;

	int sumOfCameras;
	int ms;

	void config();
	int getSumOfCameras();
	int getMs();
	~GeneralSimulator();
	GeneralSimulator();
	void sendToServer(Camera* c);
	void runThreads();
};
#endif // !generalSIMULATOR


