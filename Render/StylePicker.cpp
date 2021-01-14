#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "pugixml.hpp"

using namespace std;

fstream STYLE_FILE;

string FormatString(string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

int StylePicker(int argc, char *argv[])
{
	pugi::xml_document STYLE_FILE;
	pugi::xml_parse_result result = STYLE_FILE.load_file("StyleSheet.unigal");
	string src = FormatString(STYLE_FILE.select_single_node("/unigal-script/head/src/text()").node().value());
	string dst = FormatString(STYLE_FILE.select_single_node("/unigal-script/head/dst/text()").node().value());
	string ver = FormatString(STYLE_FILE.select_single_node("/unigal-script/head/ver/text()").node().value());
	cout << "[src=" << src << "]" << endl;
	cout << "[dst=" << dst << "]" << endl;
	cout << "[ver=" << ver << "]" << endl;
	cout << "开始解析脚本，若需要编译成目标语言则输入1，不需要编译成目标语言则输入0" << endl;
	int flag_complier = 0;
	cin >> flag_complier;
	ofstream objectfile;


	return 0;
}