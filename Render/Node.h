#include <algorithm>
#include <vector>

using namespace std;

#pragma once

#define NODE_SHAPE_RECT 11 //矩形
#define NODE_SHAPE_ECLIPSE 12 //椭圆
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
	Nodelist SourceList;
	Nodelist NextList;
	string Identification;
	int IdentificationType = NODE_IDENTIFICATION_NAME;
	int isInLoop = 0;
	//SVG INFO
	int leftupx = 0;
	int leftupy = 0;
	int width = 0;
	int higth = 0;
	int centerx = 0;
	int centery = 0;
	int radiusx = 0;
	int radiusy = 0;
	//FUNCTION
	Node();
	Node(int x, int y, int w, int h, int Shape);//For Rect
	Node(int cx, int cy, int rx, int ry, int Shape);//For eclipse
	~Node();
	void Draw();
};

Node::Node()
{
}

Node::Node(int x, int y, int w, int h,int Shape)
{
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
}

Node::Node(int cx, int cy, int rx, int ry)
{
	this->Shape = NODE_SHAPE_ECLIPSE;
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

/*
if(Shape==NODE_SHAPE_RECT)
Node(rect)
else
Node(eclipse)
*/

Node::~Node()
{
}

void Node::Draw()
{
	//输出SVG
	//但是一般不应直接调用对象来绘制，建议只使用对象来获取指定的参数填充进主函数的fstream流中，由流来完成。
	//但是如果考虑到每个节点的固定格式，其实可以调用Draw，但是为了应对各种情况，最好多提供几个可选参数。
}

class Nodelist
{
public:
	int NodeNum;
	vector<Node> Nodes;
};