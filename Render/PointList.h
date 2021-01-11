#include <algorithm>
#include <vector>

#include "Point.h"

using namespace std;

#pragma once

class PointList
{
public:
	int num;
	vector<Point> Points;
	PointList();
	~PointList();
};

PointList::PointList()
{
}

PointList::~PointList()
{
}
