#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include "VisionImage.h"

using namespace cv;
using namespace std;
class Shape
{
public:

	virtual vector<Mat> FindContours(VisionImage image) = 0;
};

