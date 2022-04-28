#pragma once
#include "Camera.h"
#include <iostream>
#include <thread>
#include <vector>
#include "Global.h"
#ifndef general
#define SIMULATOR

using namespace std::literals::chrono_literals;
using namespace std;

class GeneralSimulator
{
public:
	Camera cameraArr[sumOfCameras];
	thread* sendThreadsArr ;
	thread* runThreadsArr ;
	thread* stopThreadArr ;
	/*void runGeneralSimulator();
	void runSimulator(int i);
	void stopSimulator(int i);*/
	~GeneralSimulator();
	GeneralSimulator();
	void sendToServer(Camera *c);
	void runThreads();
};
#endif // !general


