#ifndef __CAMERA_H
#define __CAMERA_H


#include <string>
#include "../../Engine/EventHandler/EventHandler.h"
#include "../../Engine/EventHandler/Events.h"
#include "../../Services/Math/LevelUpMath.h"
#include "../../Core/DirectXViewport.h"

namespace LevelUp
{
	class View;
	class GameObject;
    class Scene;
    class CameraResizeCommand;


    //camera will draw on the screen all the objects that are on its parent scene and will draw them appropriatly
    //Alex Sabourin April 2015
	class Camera : public EventHandler
	{
	public:
		Camera();
        //create the camera for a scene
        Camera(Scene* s);
		virtual ~Camera();
        //get the cameras id
		std::string CameraID();

        //render the camera
		virtual void render();

        //set the cameras game world position
		void setPos(float x, float y);
        //set the cameras width
		void setH(float h);
        //set the cameras height
		void setW(float w);
        //get the cameras position in game space
		LVLfloat2 getPos();
        //get the cameras height
		float getH();
        //get the cameras width
		float getW();
        //get if the camera can be viewed
		bool canView();
        //set if the camera can be viewed
		void setCanView(bool b);
        //set the cameras x in game space
		void setX(float x);
        //set the cameras y in game space
		void setY(float y);
        //set the cameras x in screen space
		void setScreenX(float x);
        //set the cameras y on the screen
		void setScreenY(float y);
        //get the cameras x position on the screen
		float getScreenX();
        //get the cameras y position on the screen
		float getscreenY();
        
        //its an event handler to handle screen size events
        void handleEvent(DispatchEvents e);

        void setResizeMethod(CameraResizeCommand* c);


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
        LVLfloat2 m_currentScreenSize;
        bool m_viewPortIsDirty;
        Viewport* m_viewport;

        CameraResizeCommand* m_command;
	};
}
#endif