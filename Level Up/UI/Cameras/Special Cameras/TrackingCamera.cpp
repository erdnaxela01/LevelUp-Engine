#include "TrackingCamera.h"
#include "../Camera.h"
#include "../../../Base Class/GameObject.h"
#include <DirectXMath.h>

namespace LevelUp
{
	TrackingCamera::TrackingCamera(GameObject* go) :m_isTracking(false)
	{
		m_trackingObject = go;
        m_onScreenPos = LVLfloat2(0.5f, 0.5f);
	}
	TrackingCamera::~TrackingCamera()
	{

	}
	void TrackingCamera::setTrackingObject(GameObject* go)
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
		if (m_trackingObject == nullptr)
		{
			return;
		}
		setX(m_trackingObject->getPosition().x - m_width * m_onScreenPos.x);
		setY(m_trackingObject->getPosition().y - m_height * m_onScreenPos.y);
	}
	void TrackingCamera::setOnScreenTrackingLocation(float x, float y)
	{
		m_onScreenPos.x = x;
		m_onScreenPos.y = y;
	}
}