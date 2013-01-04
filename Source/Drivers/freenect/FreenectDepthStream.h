#ifndef _FREENECT_DEPTH_STREAM_H_
#define _FREENECT_DEPTH_STREAM_H_

#include "FreenectStream.h"


class FreenectDepthStream : public FreenectStream
{	
private:
	OniVideoMode video_mode;
	void buildFrame(void* data, OniDriverFrame* pFrame);
	
public:
	FreenectDepthStream(Freenect::FreenectDevice* pDevice);
	~FreenectDepthStream() { }

	static OniVideoMode* getSupportedVideoModes();
	inline const OniVideoMode getVideoMode() const { return video_mode; }
	OniStatus setVideoMode(OniVideoMode requested_mode);

	// from oni::driver::StreamBase
	OniStatus getProperty(int propertyId, void* data, int* pDataSize);
	OniStatus setProperty(int propertyId, const void* data, int dataSize);
};

#endif // _FREENECT_DEPTH_STREAM_H_
