#pragma once

class Color
{
public:
	int R = 0;
	int G = 83;
	int B = 255;
	//The Visual Identification System Color of BUCTSNC
	int A = 239;
	//Allow rgba PNG
	Color();
	Color(int x, int y, int z);
	Color(int x, int y, int z, int a);
	~Color();
};

Color::Color()
{
}

Color::Color(int x, int y, int z)
{
	this->R = x;
	this->G = y;
	this->B = z;
}

Color::Color(int x, int y, int z, int a)
{
	this->R = x;
	this->G = y;
	this->B = z;
	this->A = a;
}

Color::~Color()
{
}
