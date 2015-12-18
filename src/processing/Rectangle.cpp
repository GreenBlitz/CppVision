#include "Rectangle.h"

Rectangle::Rectangle(float aspectRatio, int minWidth){
	this->aspectRatio = aspectRatio;
	this->minWidth = minWidth;
	this->maxWidth = -1;
}

Rectangle::Rectangle(float aspectRatio, int minWidth, int maxWidth){
	this->aspectRatio = aspectRatio;
	this->minWidth = minWidth;
	this->maxWidth = maxWidth;
}

Rectangle::~Rectangle(){

}

vector<vector<Point> > Rectangle::FindContours(VisionImage img){
	vector<vector<Point> > contours;
	findContours(img.GetImage(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	vector<vector<Point> > foundRectangles(contours.size());
	Rect2i rectangle;
	vector<Point> polly;
	int count = 0;
	int i = 0;
	for (vector<vector<Point> >::iterator it = contours.begin(); it != contours.end(); ++it){
		approxPolyDP(Mat(*it), polly, 3, true);
		rectangle = boundingRect(polly);
		int area = rectangle.area();
		int ctrArea = contourArea(polly);
		if (area * 1.2f >= ctrArea && area * 0.85f <= ctrArea){
			float ratio = (float)rectangle.width / (float)rectangle.height;
			if ( ratio >= aspectRatio * 0.85f && ratio <= aspectRatio * 1.2f){
				if (rectangle.width >= minWidth && ( maxWidth==-1 || maxWidth >= rectangle.width)){
					vector<Point> ctrs(4);
					ctrs[0] = Point(rectangle.x, rectangle.y);
					ctrs[1] = Point(rectangle.x + rectangle.width, rectangle.y);
					ctrs[2] = Point(rectangle.x + rectangle.width, rectangle.y + rectangle.height);
					ctrs[3] = Point(rectangle.x, rectangle.y + rectangle.height);
					foundRectangles[count] = ctrs;
					count++;
				}
			}
		}
		i++;
	}
	return foundRectangles;
}

vector<Point> Rectangle::FindCenters(VisionImage img){
	vector<vector<Point> > contours;
	findContours(img.GetImage(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	vector<Point> foundCenters(contours.size());
	Rect2i rectangle;
	vector<Point> polly;
	int count = 0;
	int i = 0;
	for (vector<vector<Point> >::iterator it = contours.begin(); it != contours.end(); ++it){
		approxPolyDP(Mat(*it), polly, 3, true);
		rectangle = boundingRect(polly);
		int area = rectangle.area();
		int ctrArea = contourArea(polly);
		if (area * 1.2f >= ctrArea && area * 0.85f <= ctrArea){
			float ratio = (float)rectangle.width / (float)rectangle.height;
			if ( ratio >= aspectRatio * 0.85f && ratio <= aspectRatio * 1.2f){
				if (rectangle.width >= minWidth && ( maxWidth==-1 || maxWidth >= rectangle.width)){
					foundCenters[count] = (rectangle.br()+rectangle.tl())/2;
					count++;
				}
			}
		}
		i++;
	}
	return foundCenters;
}
