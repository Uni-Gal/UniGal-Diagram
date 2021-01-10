#include <algorithm>
#include <vector>

using namespace std;

#pragma once

#define NODE_SHAPE_RECT 1 //矩形
#define NODE_SHAPE_ECILIPSSE 2 //椭圆
#define NODE_SHAPE_PARALLELOGRAM 3 //平行四边形
#define NODE_SHAPE_DIAMOND 4 //菱形

#define NODE_TYPE_LABEL 1
#define NODE_TYPE_START 2
#define NODE_TYPE_END 3
#define NODE_TYPE_ACTION 4
#define NODE_TYPE_SWITCH 5

#define NODE_IDENTIFICATION_NAME 1
#define NODE_IDENTIFICATION_UUID 2

class Node
{
public:
	int Shape= NODE_SHAPE_RECT;
	int type = NODE_TYPE_LABEL;
	string Comment;
	Nodelist SourceList;
	Nodelist NextList;
	string Identification;
	int IdentificationType = NODE_IDENTIFICATION_NAME;

	Node();
	~Node();

};

Node::Node()
{
}

Node::~Node()
{
}

class Nodelist
{
public:
	int NodeNum;
	vector<Node> Nodes;
};