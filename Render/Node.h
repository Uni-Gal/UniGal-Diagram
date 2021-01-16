#include <algorithm>
#include <vector>

#include "Point.h"

//#include "Nodelist.h"

using namespace std;

#pragma once

#define NODE_SHAPE_RECT 11 //矩形
#define NODE_SHAPE_ELLIPSE 12 //椭圆
#define NODE_SHAPE_PARALLELOGRAM 13 //平行四边形
#define NODE_SHAPE_DIAMOND 14 //菱形

#define NODE_TYPE_LABEL 21
#define NODE_TYPE_START 22
#define NODE_TYPE_END 23
#define NODE_TYPE_ACTION 24
#define NODE_TYPE_SWITCH 25

#define NODE_IDENTIFICATION_NAME 31
#define NODE_IDENTIFICATION_UUID 32

class Node
{
public:
	//NODE INFO
	int Shape= NODE_SHAPE_RECT;
	int type = NODE_TYPE_LABEL;
	string Comment;
	//Nodelist SourceList;
	//Nodelist NextList;
	vector<Node> SourceList;
	vector<Node> NextList;
	string Identification;
	int IdentificationType = NODE_IDENTIFICATION_NAME;
	int isInLoop = 0;
	//SVG INFO
	////NUMRIC
	int width = 0;
	int higth = 0;
	int radiusx = 0;
	int radiusy = 0;
	////POINT
	int leftupx = 0;
	int leftupy = 0;
	/*
	Point Leftup;
	*/
	int centerx = 0;
	int centery = 0;
	/*
	Point Center;
	*/
	//FUNCTION
	Node();
	Node(int argv_a, int argv_b, int argv_c, int argv_d, int Shape);//For Rect & ellipse
	~Node();
	void Draw();
};

Node::Node()
{
}

Node::Node(int argv_a, int argv_b, int argv_c, int argv_d, int Shape)
{
	//一个重载当两个用，我他妈真是天（sha）才（bi）
	if (Shape == NODE_SHAPE_RECT)//For Rect
	{
		//Trans argument
		int x = argv_a;
		int y = argv_b;
		int w = argv_c;
		int h = argv_d;

		//Node::Node(int x, int y, int w, int h)
		this->Shape = NODE_SHAPE_RECT;
		//VITAL
		this->leftupx = x;
		this->leftupy = y;
		this->width = w;
		this->higth = h;
		//OPTIONAL
		this->radiusx = width / 2;
		this->radiusy = higth / 2;
		this->centerx = this->leftupx + this->radiusx;
		this->centery = this->leftupy + this->radiusy;
		//提供一种基于点对的写法，目前Node中的关键点暂不使用Point对象表示，只在箭头用，但不排除未来可能。
		/*
		this->Shape = NODE_SHAPE_RECT;
		//VITAL
		this->Leftup.x = x;
		this->Leftup.y = y;
		this->width = w;
		this->higth = h;
		//OPTIONAL
		this->radiusx = width / 2;
		this->radiusy = higth / 2;
		this->Center.x = this->Leftup.x + this->radiusx;
		this->Center.y = this->Leftup.y + this->radiusy;
		*/
	}
	else if (Shape == NODE_SHAPE_RECT)//For ellipse
	{
		//Trans argument
		int cx = argv_a;
		int cy = argv_b;
		int rx = argv_c;
		int ry = argv_d;

		//Node::Node(int cx, int cy, int rx, int ry)
		this->Shape = NODE_SHAPE_ELLIPSE;
		//VITAL
		this->centerx = cx;
		this->centery = cy;
		this->radiusx = rx;
		this->radiusy = ry;
		//OPTIONAL
		this->width = radiusx * 2;
		this->higth = radiusy * 2;
		this->leftupx = centerx - radiusx;
		this->leftupy = centery - radiusy;
	}
	else
	{
		exit(0);
	}
}

Node::~Node()
{
}

void Node::Draw()
{
	//输出SVG
	//但是一般不应直接调用对象来绘制，建议只使用对象来获取指定的参数填充进主函数的fstream流中，由流来完成。
	//但是如果考虑到每个节点的固定格式，其实可以调用Draw，但是为了应对各种情况，最好多提供几个可选参数。
}