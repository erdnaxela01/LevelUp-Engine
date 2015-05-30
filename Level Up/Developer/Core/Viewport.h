#ifndef __VIEWPORT_H
#define __VIEWPORT_H

namespace LevelUp
{
    /*
    abstract class meant to be inherited, this class is used to encapsulate all the viewports in order to have a changeable render engine
    -Alex Sabourin April 2015
    */
    class Viewport
    {
    public:
        //pure virtuals
		Viewport() {};
		virtual ~Viewport() {};
        //set the width of the viewport
        virtual void setWidth(float w) = 0;

        //set the height of the viewport
        virtual void setHeight(float h) = 0;

        //set the onscreen x location of the viewport
        virtual void setTopX(float x) = 0;
        //set the onscreen y position of the viewport
        virtual void setTopY(float y) = 0;

        //get the width of the viewport
        virtual float getWidth() const = 0;
        
        //get the height of the view port
        virtual float getHeight() const = 0;

        //get the onscreen x position of the viewport
        virtual float getX() const = 0;

        //get the onscreen y position of the viewport
        virtual float getY() const = 0;

        //set the screen to the current viewport
        virtual void setViewPort() = 0;

    };
}

#endif