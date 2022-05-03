#include "GeneralSimulator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	GeneralSimulator* g = new GeneralSimulator();
	g->runThreads();
	return 1;
}



