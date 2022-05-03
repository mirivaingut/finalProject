#pragma once
#include "Camera.h"
#include <iostream>
#include <thread>
#include <vector>
#include "Global.h"
#ifndef generalSIMULATOR
#define generalSIMULATOR

using namespace std::literals::chrono_literals;
using namespace std;
//int sumOfCameras;
class GeneralSimulator
{
public:
	//
	int sumC = getSumOfCameras();
	Camera* cameraArr = new Camera[sumOfCameras];
	thread* sendThreadsArr;
	thread* runThreadsArr;
	thread* stopThreadArr;
	/*void runGeneralSimulator();
	void runSimulator(int i);
	void stopSimulator(int i);*/
	~GeneralSimulator();
	GeneralSimulator();
	void sendToServer(Camera* c);
	void runThreads();
};
#endif // !generalSIMULATOR


