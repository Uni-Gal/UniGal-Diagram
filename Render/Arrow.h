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
	vector<Point> Route;
	Line();
	~Line();
};

Line::Line()
{
}

Line::~Line()
{
}