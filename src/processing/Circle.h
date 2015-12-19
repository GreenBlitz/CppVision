
#ifndef CIRCLE_GB_H
#define CIRCLE_GB_H

#include "Shape.h"

class Circle : public Shape{
private:
	int minRadius;
	int maxRadius;
public:
	Circle(int minRadius);
	Circle(int minRadius, int maxRadius);
	virtual ~Circle();
	vector<vector<Point> > FindContours(VisionImage image);
	vector<Point> FindCenters(VisionImage image);
};

#endif
