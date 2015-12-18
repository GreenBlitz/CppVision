
#ifndef VISION_IMAGE_GB_H
#define VISION_IMAGE_GB_H
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "../Constants.cpp"
using namespace cv;

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
	void Filter(int filter, int from[], int to[]);
	MatSize GetSize();
	VisionImage Clone();
};

#endif

