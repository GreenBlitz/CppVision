
#ifndef RECTANGLE_GB_H
#define RECTANGLE_GB_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	float aspectRatio;
	int minWidth;
	int maxWidth;
public:
	Rectangle(float aspectRatio, int minWidth);
	Rectangle(float aspectRatio, int minWidth, int maxWidth);
	~Rectangle();
	vector<vector<Point> > FindContours(VisionImage image);
	vector<Point> FindCenters(VisionImage image);

};
#endif

