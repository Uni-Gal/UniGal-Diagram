#include <iostream>
#include <fstream>

using namespace std;

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

	//SVG

	return 0;
}