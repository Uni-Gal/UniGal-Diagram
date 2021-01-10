#include <algorithm>
#include <vector>
#include "Point.h"

using namespace std;

#pragma once

class Arrow
{
public:
	Arrow();
	~Arrow();
	//Line Main;
	//Line Left;
	//Line Right;
	Line Body;
	Line Head;
};

Arrow::Arrow()
{
}

Arrow::~Arrow()
{
}

class Line
{
public:
	PointList Route;
	Line();
	~Line();
};

Line::Line()
{
}

Line::~Line()
{
}