#ifndef __TRACKINGCAMERA_H
#define __TRACKINGCAMERA_H

#include "../Camera.h"
#include "../../../Engine/MVC/Model.h"
#include <DirectXMath.h>

namespace LevelUp
{
	class GameObject;
    //this camera will track an object as it moves
    //Alex Sabourin April 2015
	class TrackingCamera : public Camera, public Model
	{
	public:
		TrackingCamera(GameObject* go = nullptr);
		virtual ~TrackingCamera();
        //set the tracking object
		void setTrackingObject(GameObject* go);
        //set if it does track
		void setIsTracking(bool b);
        //check if it is tracking
		bool isTracking();
        //update the tracking
		void update(double delta);
        //set the location to track the object
		void setOnScreenTrackingLocation(float x, float y);
	private:
		GameObject* m_trackingObject;
		bool m_isTracking;
        LVLfloat2 m_onScreenPos;
	};
}


#endif