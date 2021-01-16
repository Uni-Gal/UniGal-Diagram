#include <iostream>
#include <fstream>
#include <string>

#include "Arrow.h"
#include "Node.h"
#include "Point.h"
#include "Text.h"

#include "StylePicker.cpp"

using namespace std;

#pragma once

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

class viewBox
{
public:
	//VITAL
	int L = 0;
	int U = 0;
	int R = 320;
	int D = 650;
	//FUNCTION
	void setViewBox(int L, int U, int R, int D)
	{
		this->L = L;
		this->U = U;
		this->R = R;
		this->D = D;
	}
};

viewBox SVG;

string argv_viewBox()
{
	string argv_viewBox = "";
	{
		//argv_viewBox = argv_viewBox + SVG.L + "," + SVG.U + "," + SVG.R + "," + SVG.D;
	}
	return argv_viewBox;
}

string argv_background_style_fill_rgb()
{
	string argv_background_style_fill_rgb = "";
	{
		;
	}
	return argv_background_style_fill_rgb;
}

int main_Frontend(void)
{
	IO_FILE.open("simple.svg", ios::out);
	
	int deepth = 0;

	Style StyleSheet;
	//StylePicker(StyleSheet);
	
#ifdef _DEBUG
	StyleSheet.background_exist = true;
	StyleSheet.frame_exist = true;
#endif // _DEBUG


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
	//////BACKGROUND
	if (StyleSheet.background_exist == true)
	{
		//有背景
		//需要绘制背景
		cout << spaceLevel(deepth) << "<!-- Element:background -->" << endl;
		cout << spaceLevel(deepth) << "<rect" << endl;
		deepth += 1;
		{
			//是固定原点故硬编码(0,0)点
			cout << spaceLevel(deepth) << "x=\"" << "0" << "\"" << endl;
			cout << spaceLevel(deepth) << "y=\"" << "0" << "\"" << endl;
			cout << spaceLevel(deepth) << "width=\"" << SVG.R << "\"" << endl;
			cout << spaceLevel(deepth) << "height=\"" << SVG.D << "\"" << endl;

			cout << spaceLevel(deepth) << "style=" << endl;
			cout << spaceLevel(deepth) << "\"" << endl;
			deepth += 1;
			{
				cout << spaceLevel(deepth) << "fill:rgb(" << StyleSheet.background_fillcolor.R << "," << StyleSheet.background_fillcolor.G << "," << StyleSheet.background_fillcolor.B << ")" << endl;
				//准备后续完善后改成cout << spaceLevel(deepth) << "fill:rgb(" << argv_background_style_fill_rgb() << ")" << endl;
			}
			deepth -= 1;
			cout << spaceLevel(deepth) << "\"" << endl;
		}
		deepth -= 1;
		cout << spaceLevel(deepth) << "/>" << endl;
	}
	else if (StyleSheet.background_exist == false)
	{
		//无背景
		//什么都不做
	}
	else
	{
		//出错了
		//输出报错信息
		cout << spaceLevel(deepth) << "<!-- StyleSheet.background_exist may not be bool variable -->" << endl;
	}
	//////FRAME
	if (StyleSheet.frame_exist == true)
	{
		//有边框
		//需要绘制边框
		cout << spaceLevel(deepth) << "<!-- Element:background -->" << endl;
		cout << spaceLevel(deepth) << "<rect" << endl;
		deepth += 1;
		{
			cout << spaceLevel(deepth) << "x=\"" << "0" << "\"" << endl;
			cout << spaceLevel(deepth) << "y=\"" << "0" << "\"" << endl;
			cout << spaceLevel(deepth) << "width=\"" << SVG.R - 2 * StyleSheet.frame_x_border << "\"" << endl;
			cout << spaceLevel(deepth) << "height=\"" << SVG.D - 2 * StyleSheet.frame_y_border << "\"" << endl;
			cout << spaceLevel(deepth) << "rx=\"" << StyleSheet.frame_x_radius << "\"" << endl;
			cout << spaceLevel(deepth) << "ry=\"" << StyleSheet.frame_y_radius << "\"" << endl;

			cout << spaceLevel(deepth) << "style=" << endl;
			cout << spaceLevel(deepth) << "\"" << endl;
			deepth += 1;
			{
				cout << spaceLevel(deepth) << "fill:rgb(" << StyleSheet.frame_fillcolor.R << "," << StyleSheet.frame_fillcolor.G << "," << StyleSheet.frame_fillcolor.B << ")" << endl;
				cout << spaceLevel(deepth) << "stroke-width:" << StyleSheet.frame_strokewidth << endl;
				cout << spaceLevel(deepth) << "fill:rgb(" << StyleSheet.frame_strokecolor.R << "," << StyleSheet.frame_strokecolor.G << "," << StyleSheet.frame_strokecolor.B << ")" << endl;
				cout<< spaceLevel(deepth) <<"fill-opacity:" << StyleSheet.frame_fillopacity << endl;
				cout << spaceLevel(deepth) << "stroke-opacity:" << StyleSheet.frame_strokeopacity << endl;
			}
			deepth -= 1;
			cout << spaceLevel(deepth) << "\"" << endl;
		}
		deepth -= 1;
		cout << spaceLevel(deepth) << "/>" << endl;
	}
	else if (StyleSheet.frame_exist == false)
	{
		//无边框
		//什么都不做
	}
	else
	{
		//出错了
		//输出报错信息
		cout << "<!-- StyleSheet.frame_exist may not be bool variable -->" << endl;
	}
	//////NODE

	//////ARROW

	deepth -= 1;

	////SVGTAIL
	IO_FILE << "</svg>" << endl << endl;
	
	return 0;
}
