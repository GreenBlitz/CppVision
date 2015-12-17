#include "VisionImage.h"




VisionImage::VisionImage(Mat image)
{
	Construct(image, Mat(image.rows, image.cols, CV_32S));
}

VisionImage::VisionImage(Mat image, Mat depth)
{
	Construct(image, depth);
}

Mat VisionImage::GetImage() {
	return this->image;
}
Mat VisionImage::GetDepth() {
	return this->depth;
}
void VisionImage::Dilate() {
	dilate(image, image, Mat());
}
void VisionImage::Erode() {
	erode(image, image, Mat());
}

//This method receives 3 parameters; the color filter, the minimum filter (RGB/HSV, 3 ints in an array) and
//the maximum filter
void VisionImage::Filter(ColorFilter filter, int from[], int to[]) {
	Mat min = Mat(1, 1, CV_8U, 3);
	Mat max = Mat(1, 1, CV_8U, 3);
	//This matches the values of the rgb to a 32int
	min.at<Vec3b>(0, 0) = Vec3b(from[2], from[1], from[0]);
	max.at<Vec3b>(0, 0) = Vec3b(to[2], to[1], to[0]);
	Mat clone = image.clone();
	if (filter == ColorFilter::HSV_FILTER) {
		min.at<Vec3b>(0, 0) = Vec3b(from[0], from[1], from[2]);
		max.at<Vec3b>(0, 0) = Vec3b(to[0], to[1], to[2]);
		cvtColor(image, clone, CV_BGR2HSV);
	}
	inRange(clone, min, max, image);
}

VisionImage::~VisionImage() {}


void VisionImage::Construct(Mat image, Mat depth) {
	this->image = image;
	this->depth = depth;
}
