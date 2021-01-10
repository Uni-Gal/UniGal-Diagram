#include <iostream>
#include <fstream>

using namespace std;

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
		}
	}
	else
	{
		return "<!-- LEVEL_ERROR -->";
	}
}

int main(void)
{
	fstream IO_FILE;
	IO_FILE.open("simple.svg", ios::out);
	
	//HEADER
	IO_FILE << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl << endl;
	IO_FILE << "<!";
	IO_FILE << "DOCTYPE svg PUBLIC" << endl;
	IO_FILE << "  \" -//W3C//DTD SVG 1.1//EN\"" << endl;
	IO_FILE << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"" << endl;
	IO_FILE << ">";// << endl;

	//NODELIST
	IO_FILE << "<!--" << endl << endl;
	IO_FILE << "Node-list" << endl << endl;
	////FILENAME
	IO_FILE << "-->" << endl << endl;

	//SVG

	////SVGHEADER
	IO_FILE << "<!--" << endl << endl;
	////SVGCONTENT

	////SVGTAIL
	IO_FILE << "</svg>" << endl << endl;

	return 0;
}