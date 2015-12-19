
#ifndef STREAMING_DEVICE_GB_H
#define STREAMING_DEVICE_GB_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "../processing/VisionImage.h"
#include "FrameListener.h"
using namespace cv;

class StreamingDevice {
private:
	FrameListener listener;
protected:
	virtual Mat GetLastDepth();
	virtual bool HasDepth();
	virtual Mat GetLastImage() = 0;
	void NewFrameRecieved();
public:
	StreamingDevice();
	virtual ~StreamingDevice();
	VisionImage GetLatestFrame();
	void SetListener(FrameListener listener);
};

#endif
