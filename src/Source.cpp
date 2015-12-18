
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include "processing/VisionImage.h"
#include "processing/Rectangle.h"
#include "processing/Circle.h"
#include "Constants.cpp"
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
	VisionImage img = VisionImage(image.clone());
	int arr[3] = {70, 120, 0};
	int arr1[3] = {120 , 255, 255 };
	img.Filter(HSV_FILTER, arr, arr1);
	Rectangle rectangle = Rectangle(0.5f, 1);
	Circle circle = Circle(1);
	Mat mat2 = image.clone();
	img.Erode();
	img.Dilate();
	//img.Dilate();
	//img.Dilate();
	//img.Dilate();
	vector<vector<Point> > contours = circle.FindContours(img.Clone());
	for (size_t idx = 0; idx < contours.size(); idx++) {
		drawContours(mat2, contours, idx, Scalar(255,255,0), 3);
	}

	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	//cout << contours.size();
	imshow("Display window", img.GetImage()); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	imshow("Display window", mat2); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
