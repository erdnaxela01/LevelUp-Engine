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
		std::string viewID() const;
        //set if it can be seen
		void setCanView(bool b);
        //can you see it?
		bool canView() const;

        //get the x
		virtual float getX() const = 0;
        //get the y
		virtual float getY() const = 0;
        //get the height
		virtual float getH() const = 0;
        //get the width
		virtual float getW() const = 0;
        //set the x
		virtual void setX(float x) = 0;
        //set the y
		virtual void setY(float y) = 0;
        //can set which cameras its drawn on
		bool usesCameraVector() const;
        //add a camera to the camera vector
		void addCamera(Camera* c);
        //remove the camera
		void removeCamera(Camera* c);
        //set if it uses a camera vector
		void setUseCameraVector(bool b);
        //checks if a specific camera is part of the vector
		bool isPartOfCameraVector(std::string cameraID) const;
        //can set the depth to decide who gets drawn first
		float getZ() const;
        //set the depth
		void setZ(float z);
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
        std::string m_parentScene;

	};
}
#endif