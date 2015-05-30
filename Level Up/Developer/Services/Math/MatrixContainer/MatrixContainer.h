#ifndef __MATRIXCONTAINER_H
#define __MATRIXCONTAINER_H

#include "../DataTypes.h"

namespace LevelUp
{
    /*
    abstract class in order to change what matrix it contains
    */
    class MatrixContainer
    {
    public:
		MatrixContainer() {};
		virtual ~MatrixContainer() {};
        //set a float at a specific location
        virtual void setFloatAt(int r, int c, LVLfloat f) = 0;
        //get the float at a specific location
        virtual LVLfloat getFloatAt(int r, int c) = 0; 
    };
}

#endif