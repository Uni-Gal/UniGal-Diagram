#include <iostream>
#include <fstream>
#include <string>

#include "Arrow.h"
#include "Node.h"
#include "Point.h"
#include "Text.h"

#include "UniGal-DiagramRender.cpp"

using namespace std;

extern fstream IO_FILE;

string spaceLevel(int num)
{
	if (num <= 0)
	{
		return "";
	}
	else if (num > 0)
	{
		string singalSpaceLevel = "  ";
		string polySpaceLevel;
		if (num == 1)
		{
			polySpaceLevel = singalSpaceLevel;
			return polySpaceLevel;
		}
		else
		{
			polySpaceLevel = singalSpaceLevel;
			for (int i = 1; i <= num; ++i)
			{
				polySpaceLevel = polySpaceLevel + singalSpaceLevel;
			}
			return polySpaceLevel;
		}
	}
	else
	{
		return "<!-- LEVEL_ERROR -->";
	}
}

string argv_viewBox()
{
	string viewBox;
	return viewBox;
}

int main_Frontend(void)
{
	IO_FILE.open("simple.svg", ios::out);
	
	int deepth = 0;

	//HEADER
	deepth += 1;
	IO_FILE << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl << endl;
	deepth -= 1;

	deepth += 1;
	IO_FILE << "<!";
	IO_FILE << "DOCTYPE svg PUBLIC" << endl;
	IO_FILE << spaceLevel(deepth) << "\" -//W3C//DTD SVG 1.1//EN\"" << endl;
	IO_FILE << spaceLevel(deepth) << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"" << endl;
	IO_FILE << ">" << endl;
	deepth -= 1;

	//NODELIST
	IO_FILE << "<!--" << endl << endl;
	IO_FILE << "Node-list" << endl << endl;
	////FILENAME
	IO_FILE << "-->" << endl << endl;

	//SVG

	////SVGHEADER
	deepth += 1;
	IO_FILE << "<svg" << endl;
	IO_FILE << spaceLevel(deepth) << "viewBox=" << "\"" << argv_viewBox() << "\"" << endl;
	IO_FILE << spaceLevel(deepth) << "xmlns=" << "\"" << "http://www.w3.org/2000/svg" << "\"" << endl;
	IO_FILE << spaceLevel(deepth) << "version=" << "\"" << "1.1" << "\"" << endl;
	IO_FILE << ">" << endl;
	deepth -= 1;
	////SVGCONTENT
	deepth += 1;
	deepth -= 1;

	////SVGTAIL
	IO_FILE << "</svg>" << endl << endl;
	
	return 0;
}
