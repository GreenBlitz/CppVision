
#include "Circle.h"

Circle::Circle(int minRadius) {
	this->minRadius = minRadius;
	this->maxRadius = -1;
}

Circle::Circle(int minRadius, int maxRadius) {
	this->minRadius = minRadius;
	this->maxRadius = maxRadius;
}

Circle::~Circle() {
}

vector<vector<Point> > Circle::FindContours(VisionImage img){
	vector<vector<Point> > contours;
	findContours(img.GetImage(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	vector<vector<Point> > foundCircles(contours.size());
	Point_<float> center;
	vector<Point> polly(contours.size());
	float radius;
	int count = 0;
	int i = 0;
	for (vector<vector<Point> >::iterator it = contours.begin(); it != contours.end(); ++it){
		approxPolyDP(Mat(*it), polly, 3, true);


		float radius;
		minEnclosingCircle(polly, center, radius);
		int ctrArea = contourArea(polly);
		//The area of a circle is pi times the radius squared.
		float area = 3.141f * radius * radius;
		if (area * 1.2f >= ctrArea && area * 0.85f <= ctrArea){
			if (minRadius <= radius && (maxRadius==-1 || maxRadius >= radius) ){
				foundCircles[count] = polly;
				count++;
			}
		}
		i++;
	}
	return foundCircles;
}

vector<Point> Circle::FindCenters(VisionImage img){
	vector<vector<Point> > contours;
	findContours(img.GetImage(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	vector<Point> foundCenters(contours.size());
	Point_<float> center;
	vector<Point> polly(contours.size());
	float radius;
	int count = 0;
	int i = 0;
	for (vector<vector<Point> >::iterator it = contours.begin(); it != contours.end(); ++it){
		approxPolyDP(Mat(*it), polly, 3, true);
		float radius;
		minEnclosingCircle(polly, center, radius);
		int ctrArea = contourArea(polly);
		//The area of a circle is pi times the radius squared.
		float area = 3.141f * radius * radius;
		if (area * 1.2f >= ctrArea && area * 0.85f <= ctrArea){
			if (minRadius <= radius && (maxRadius==-1 || maxRadius >= radius) ){
				foundCenters[count] = center;
				count++;
			}
		}
		i++;
	}
	return foundCenters;
}
