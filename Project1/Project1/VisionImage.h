#pragma once
#include <opencv2/opencv.hpp>
#include "ColorFilter.cpp"
using namespace cv;
//
class VisionImage
{
private:
	Mat image;
	Mat depth;
	void Construct(Mat image, Mat depth);
public:
	VisionImage(Mat image, Mat depth);
	VisionImage(Mat image);
	~VisionImage();
	Mat GetImage();
	Mat GetDepth();
	void Dilate();
	void Erode();
	void Filter(ColorFilter filter, int from[], int to[]);
};

