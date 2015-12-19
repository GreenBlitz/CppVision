
#ifndef FRAME_LISTENER_GB_H
#define FRAME_LISTENER_GB_H

#include "../processing/VisionImage.h"

class FrameListener {
public:
	FrameListener();
	virtual ~FrameListener();
	virtual void OnNewFrame(VisionImage image);
};

#endif
