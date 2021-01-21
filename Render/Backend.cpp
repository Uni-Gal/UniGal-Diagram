#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Node.h"
#include "Point.h"
#include "pugixml.hpp"

using namespace std;

#pragma once

int main_Backend(void)
{
	//pugi::xml_document DIAGRAM_FILE;
	//pugi::xml_parse_result result = DIAGRAM_FILE.load_file("StyleSheet.unigal");


	int Num_Node = 3;//min is 3
	//考虑到有多个节点的情况
	int iterator_i = 0;
	vector<pugi::xml_document> DIAGRAM_FILE_LIST;
	for (iterator_i = 0; iterator_i < Num_Node; ++iterator_i)
	{
		pugi::xml_document temp;
		DIAGRAM_FILE_LIST.push_back(temp);
	}
	vector<char[10000]> DIAGRAM_FILENAME_LIST;
	vector<pugi::xml_parse_result> DIAGRAM_RESULT;
	for (iterator_i = 0; iterator_i < Num_Node; ++iterator_i)
	{
		pugi::xml_parse_result result = DIAGRAM_FILE_LIST[iterator_i].load_file(DIAGRAM_FILENAME_LIST[iterator_i]);
		DIAGRAM_RESULT.push_back(result);
	}

	return 0;
}
