#include "setting.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	//setting init,parse command line && config file
	Setting::GetInstance().Init(argc, argv);

	//business logic 

	return 0;
}
