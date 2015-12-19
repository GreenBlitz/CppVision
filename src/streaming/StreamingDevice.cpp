
#include "StreamingDevice.h"

StreamingDevice::StreamingDevice() {
	this->listener = FrameListener();
}

StreamingDevice::~StreamingDevice() {
}

VisionImage StreamingDevice::GetLatestFrame(){
	if (HasDepth()){
		return VisionImage(GetLastImage(), GetLastDepth());
	} else {
		return VisionImage(GetLastImage());
	}
}

Mat StreamingDevice::GetLastDepth(){
	return Mat();
}

void StreamingDevice::SetListener(FrameListener listener){
	this->listener = listener;
}

bool StreamingDevice::HasDepth(){
	return false;
}

void StreamingDevice::NewFrameRecieved(){
	listener.OnNewFrame(GetLatestFrame());
}
