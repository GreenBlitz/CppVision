#include "VisionImage.h"




VisionImage::VisionImage(Mat image)
{
	Construct(image, Mat(image.size, CV_32S));
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

MatSize VisionImage::GetSize(){
	return image.size;
}

VisionImage VisionImage::Clone(){
	return VisionImage(image.clone(),depth.clone());
}




//This method receives 3 parameters; the filter type, the minimum filter (RGB/HSV, 3 ints in an array,
//or a depth, one int in the array) and the maximum filter (Same as minimum filter)
void VisionImage::Filter(int filter, int from[], int to[]) {
	//This matches the values of the filtering into scalars

	Scalar min;
    Scalar max;
    Mat source = image;
    if (filter == RGB_FILTER){
    	min = Scalar(from[2], from[1], from[0]);
    	max = Scalar(to[2], to[1], to[0]);
    } else if (filter == HSV_FILTER) {
		min = Scalar(from[0], from[1], from[2]);
		max = Scalar(to[0], to[1], to[2]);
		cvtColor(image, source, CV_BGR2HSV);
	} else if (filter == DEPTH_FILTER){
		min = Scalar(from[0]);
		max = Scalar(to[0]);
<<<<<<< HEAD
		source = Mat(image.rows, image.cols, CV_8U);
=======
		source = Mat(image.size, CV_8U);
>>>>>>> origin/master
		depth.copyTo(source, image);
	}
	inRange(source, min, max, image);

}

VisionImage::~VisionImage() {}


void VisionImage::Construct(Mat image, Mat depth) {
	this->image = image;
	this->depth = depth;
}
