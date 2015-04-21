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
		void setTrackingObject(GameObject* go);
		void setIsTracking(bool b);
		bool isTracking();
		void update(double delta);
		void setOnScreenTrackingLocation(float x, float y);
	private:
		GameObject* m_trackingObject;
		bool m_isTracking;
        LVLfloat2 m_onScreenPos;
	};
}


#endif