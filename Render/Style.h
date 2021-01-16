#include <iostream>
#include <string>

#include "Color.h"

using namespace std;

#pragma once

class Style
{
public:
	//Background
	bool background_exist = false;
	Color background_fillcolor;
	float background_opacity = 1.00;

	//Frame
	bool frame_exist = false;
	int frame_x_border = 0;
	int frame_y_border = 0;
	float frame_x_radius = 0;
	float frame_y_radius = 0;
	Color frame_fillcolor;
	Color frame_strokecolor;
	float frame_fillopacity = 1.00;
	float frame_strokeopacity = 1.00;
	float frame_strokewidth = 1.00;

	//Node
	Color node_fillcolor;
	Color node_strokecolor;
	float node_fillopacity = 1.00;
	float node_strokeopacity = 1.00;
	float node_strokewidth = 1.00;

	//Text
	int text_font_size = 20;
	string text_font_family;
	Color text_color;
	bool text_bold = false;
	bool text_italic = false;
	bool text_shadow = false;
	float text_opacity = 1.00;
	/*Color text_color_start;*/
	/*Color text_color_end;*/

	//Arrow
	float arrow_width = 1.00;
	int arrow_headsize = 10;
	bool arrow_roundtail = false;

	//Function
	Style();
	void setBackgroundStyle(bool exist, Color fillcolor, float opacity);
	~Style();
};

Style::Style()
{
}

void Style::setBackgroundStyle(bool exist, Color fillcolor, float opacity)
{
	this->background_exist = exist;
	this->background_fillcolor = fillcolor;
	this->background_opacity = opacity;
}

Style::~Style()
{
}