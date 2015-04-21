#ifndef __CAMERA_H
#define __CAMERA_H


#include <string>
#include <DirectXMath.h>
#include <d3d11.h>
#include "../../Engine/EventHandler/EventHandler.h"
#include "../../Engine/EventHandler/Events.h"
#include "../../Services/Math/LevelUpMath.h"

namespace LevelUp
{
	class View;
	class GameObject;
    class Scene;


    //camera will draw on the screen all the objects that are on its parent scene and will draw them appropriatly
    //Alex Sabourin April 2015
	class Camera : public EventHandler
	{
	public:
		Camera();
        Camera(Scene* s);
		virtual ~Camera();
		std::string CameraID();

		virtual void render();

		void setPos(float x, float y);
		void setH(float h);
		void setW(float w);
		LVLfloat2 getPos();
		float getH();
		float getW();
		bool canView();
		void setCanView(bool b);
		void setX(float x);
		void setY(float y);
		void setScreenX(float x);
		void setScreenY(float y);
		float getScreenX();
		float getscreenY();
        
        void handleEvent(DispatchEvents e);


	protected:
		std::string m_ID;
		std::string m_parentScene;
		float m_x;
		float m_y;
		float m_height;
		float m_width;
		bool m_canView;
		static int m_numberOfCameras;
        LVLfloat2 m_screenPos;
		D3D11_VIEWPORT m_viewport;
        LVLfloat2 m_currentScreenSize;
        bool m_viewPortIsDirty;
	};
}
#endif