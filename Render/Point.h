#include <iostream>

using namespace std;

#pragma once

class Point
{
public:
	int x = 0;
	int y = 0;
	Point();
	Point(int X, int Y);
	~Point();
};

Point::Point()
{
}

Point::Point(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

Point::~Point()
{
}
