#ifndef __MATRIXCONTAINER_H
#define __MATRIXCONTAINER_H

#include "../DataTypes.h"

namespace LevelUp
{
    class MatrixContainer
    {
    public:
        virtual void setFloatAt(int r, int c, LVLfloat f) = 0;
        virtual LVLfloat getFloatAt(int r, int c) = 0; 
    };
}

#endif