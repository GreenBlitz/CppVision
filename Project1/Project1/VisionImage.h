#pragma once
#include <opencv2/opencv.hpp>
#include "ColorFilter.cpp"
using namespace cv;

class VisionImage
{
public:
	VisionImage();
	~VisionImage();
	Mat GetImage();
	Mat GetDepth();
	void Dilate();
	void Erode();
	void Filter(ColorFilter);
};

