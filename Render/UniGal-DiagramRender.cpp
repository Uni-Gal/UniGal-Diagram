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
	main_Backend();
	main_Frontend();
	return 0;
}
