#include "TrackingCamera.h"
#include "../Camera.h"
#include "../../../Engine/BasicLevelObject/BaseLevelObject.h"

namespace LevelUp
{
	TrackingCamera::TrackingCamera(BaseLevelObject* go) :m_isTracking(false)
	{
		m_trackingObject = go;
        m_onScreenPos = LVLfloat2(0.5f, 0.5f);
	}
	TrackingCamera::~TrackingCamera()
	{

	}
	void TrackingCamera::setTrackingObject(BaseLevelObject* go)
	{
		m_trackingObject = go;
	}
	void TrackingCamera::setIsTracking(bool b)
	{
		m_isTracking = b;
	}
	bool TrackingCamera::isTracking()
	{
		return m_isTracking;
	}
	void TrackingCamera::update(double delta)
	{
		if (m_trackingObject == nullptr || m_isTracking == false)
		{
			return;
		}
        //set the cameras location with the obbjects location
		setX(m_trackingObject->getPosition().x - m_width * m_onScreenPos.x);
		setY(m_trackingObject->getPosition().y - m_height * m_onScreenPos.y);
	}
	void TrackingCamera::setOnScreenTrackingLocation(float x, float y)
	{
		m_onScreenPos.x = x;
		m_onScreenPos.y = y;
	}
}