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
				if (abs(StyleSheet.background_opacity - 1.00) <= 0.001)
				{
					cout << spaceLevel(deepth) << "fill-opacity:" << StyleSheet.background_opacity << endl;
				}
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
		cout << spaceLevel(deepth) << "<!-- Element:frame -->" << endl;
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
				if (abs(StyleSheet.frame_fillopacity - 1.00) <= 0.001)
				{
					cout << spaceLevel(deepth) << "fill-opacity:" << StyleSheet.frame_fillopacity << endl;
				}
				if (abs(StyleSheet.frame_strokeopacity - 1.00) <= 0.001)
				{
					cout << spaceLevel(deepth) << "stroke-opacity:" << StyleSheet.frame_strokeopacity << endl;
				}
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

	typedef struct NodePosition
	{
		string NodeName;
		Node Nodeatthis;
		Point Position;
	}NodePosition;
	//该结构体将被Node和Text的绘制过程调用，也会被Arrow的过程拿来计算，可以说是后面三部分的共有的了。

	int Num_Node;
	//重头戏：计算Node的数量和位置。
	//首先Node应该分成多个层次，至少分为start的周目一行，然后end的结局一行，中间的若干个行另外记。
	int Num_Node_Startline;//start行的Node数量
	int Num_Node_Endline;//end行的Node数量
	int Num_Node_Plotheight;//plot行深度是多少
	int Num_Node_Plotwide_Max;
	int Num_Node_Plotwide_Min;
	vector<int> Num_Node_PlotwideList;
	//以上信息应该由后端读取后产生，然后包括节点位置在内，不应该由前端部分计算，应由后端部分计算。这些的定义应该放进main函数去做，并传递给前端。留待后续优化

	//////TEXT
	int Num_Text;
	//重头戏：文字的位置需要沿用上文的Node的位置.

	//////ARROW
	int Num_Arrow;
	//重头戏：根据获取到的Node的位置坐标和Node对象里面获取到的高度等信息，推算不同线段的起始点和终点，然后根据这些来绘图。

	deepth -= 1;

	////SVGTAIL
	IO_FILE << "</svg>" << endl << endl;
	
	return 0;
}
