#pragma once

#include "Shape.h"


class Rectangle : public Shape
{
private:
	float aspectRatio;
	int minWidth;
public:
	Rectangle(float aspectRatio, int minWidth);
	~Rectangle();
	vector<Mat> FindContours(VisionImage image);

};

