#include <algorithm>
#include <vector>

#include "Line.h"

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