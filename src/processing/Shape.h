
#ifndef SHAPE_GB_H
#define SHAPE_GB_H
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include "VisionImage.h"

using namespace cv;
using namespace std;
class Shape
{
public:
	Shape();
	virtual ~Shape() = 0;
	virtual vector<vector<Point> > FindContours(VisionImage image) = 0;
	virtual vector<Point> FindCenters(VisionImage image) = 0;
};
#endif
