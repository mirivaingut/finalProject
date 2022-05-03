#include <iostream>
#include <fstream>
#include <string>
#include "Global.h"

using namespace std;

void config() {
	int arr[2];
	int index = 0;
	fstream newfile;

	newfile.open("conf.txt", ios::in);
	if (newfile.is_open()) {
		string tp;
		while (getline(newfile, tp)) {
			int f = tp.find(':');
			int l = tp.find('.');
			arr[index++] = stoi(tp.substr(f + 1, l - (f + 1)));
			cout << arr[index - 1] << "\n";
		}
		newfile.close();
	}
	setSumOfCameras(arr[0]);
	setMs(arr[1]);
}

int getSumOfCameras() {
	return sumOfCameras;
}

int getMs() {
	return ms;
}

void setSumOfCameras(int s) {
	sumOfCameras = s;
}
void setMs(int m) {
	ms = m;
}
