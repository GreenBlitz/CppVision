#include <opencv2/opencv.hpp>
#include <iostream>
#include "VisionImage.h"
#include "Rectangle.h"
using namespace cv;
using namespace std;
//
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	Mat image;
	image = imread(argv[1], IMREAD_COLOR); // Read the file

	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	VisionImage img = VisionImage(image);
	int arr[3] = {0, 0, 0};
	int arr1[3] = { 150, 150, 150 };
	img.Filter(ColorFilter::HSV_FILTER, arr, arr1); 
	Rectangle rectangle = Rectangle(0.5f, 1);
	Mat mat2 = Mat(img.GetImage().size(), CV_8UC3);
	img.Dilate();
	img.Dilate();
	vector<Mat> contours = rectangle.FindContours(VisionImage(img.GetImage()));
	//for (size_t idx = 0; idx < contours.size(); idx++) {
	//	cv::drawContours(mat2, contours, idx, 255);
	//}
	imshow("Display window", img.GetImage()); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}