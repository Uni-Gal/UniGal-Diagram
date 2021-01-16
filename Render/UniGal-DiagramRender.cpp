#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "Frontend.cpp"
#include "Backend.cpp"

#include "Arrow.h"
#include "Node.h"
#include "Point.h"
#include "Text.h"

using namespace std;

int main(int argc, char *argv[])
{
	//main_Backend();//节省前期调式阶段编译时间
	main_Frontend();
	return 0;
}
