#include "GeneralSimulator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//void config() {
//	int arr[2];
//	int index = 0;
//	fstream newfile;
//
//	newfile.open("conf.txt", ios::in);
//	if (newfile.is_open()) {
//		string tp;
//		while (getline(newfile, tp)) {
//			int f = tp.find(':');
//			int l = tp.find('.');
//			arr[index++] = stoi(tp.substr(f + 1, l - (f + 1)));
//			cout << arr[index - 1] << "\n";
//		}
//		newfile.close();
//	}
//	sumC =new int(arr[0]);
//	ms = new int(arr[1]);
//}
int main()
{
int sumC = getSumOfCameras();
//	config();
	//cout << "sum::::::::" << sumC << " , " << ms;
	GeneralSimulator* g = new GeneralSimulator();
	g->runThreads();
	for (int i = 0; i < sumC; i++) {
		//g->sendThreadsArr[i].join();
		g->runThreadsArr[i].join();
		g->stopThreadArr[i].join();
	}
	for (int i = 0; i <sumC ; i++)
	{
		cout << "print " << "camera arr " << (i + 1) << ":\n";
	}
	return 1;
}



