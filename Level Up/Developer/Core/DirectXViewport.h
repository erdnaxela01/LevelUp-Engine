#ifndef __DIRECTXVIEWPORT_H
#define __DIRECTXVIEWPORT_H

#include <d3d11.h>
#include "Viewport.h"

namespace LevelUp
{
    /*
   inherited form viewport this class is used to create a direct x 11.1 viewport for viewing things on screen
    -Alex Sabourin April 2015
    */

    class DirectXViewport : public Viewport
    {
    public:

        //constructor
        DirectXViewport();
        //set the width of the viewport
        void setWidth(float w);
        //set the height of the viewport
        void setHeight(float h);
        //set the screen x location of the viewport
        void setTopX(float x);
        //set the screen y location of the viewport
        void setTopY(float y);

        //return the width of the viewport
        float getWidth();
        //return the heigh of the viewport
        float getHeight();
        //get the viewports x position on the screen
        float getX();
        //get the viewports y position on the screenm
        float getY();


        //set the views current viewports
        void setViewPort();
    private:
        //the viewport
        D3D11_VIEWPORT m_viewport;

    };
}


#endif