#ifndef __VIEW_H
#define __VIEW_H

#include <string>
#include <vector>

namespace LevelUp
{
	class Camera;

    //used for an object to be drawn part of MVC
    //Alex Sabourin April 2015
	class View
	{
	public:
		View(float z = 1.0f);
		virtual ~View();
		virtual void render() = 0;
        //what is the views id
		std::string ViewID();
		void setCanView(bool b);
		bool canView();

        //get the parameters of the object
		virtual float getX() = 0;
		virtual float getY() = 0;
		virtual float getH() = 0;
		virtual float getW() = 0;
		virtual void setX(float x) = 0;
		virtual void setY(float y) = 0;
        //can set which cameras its drawn on
		bool usesCameraVector();
		void addCamera(Camera* c);
		void removeCamera(Camera* c);
		void setUseCameraVector(bool b);
		bool isPartOfCameraVector(std::string cameraID);
        //can set the depth to decide who gets drawn first
		float getZ();
		void setZ(float z);
        friend Camera;
        //for z sorting
		bool operator< (View &rhs) { return this->getZ() > rhs.getZ(); }
	protected:
		virtual void addToMap();
        virtual void removeFromMap();
		std::string m_ID;
		float m_z;
	private:
		static int m_numberOfViews;
		bool m_canView;
		bool m_useCameraVector;
		std::vector<Camera*> m_activeCameras;
        //object must be able to get drawn somewhere else for the camera
        virtual void render(float x, float y) = 0;

	};
}
#endif