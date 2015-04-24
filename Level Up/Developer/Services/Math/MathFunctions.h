#ifndef __MATHFUNCTIONS_H
#define __MATHFUNCTIONS_H

#include "DataTypes.h"

namespace LevelUp
{
    /*
    All existing Level Up engine Math functions used for Level Up math
    Alex Sabourin
    */

    //row major (can be changed by adapter)
    LVL4X4matrix translationMatrix2D(LVLfloat2 f);
    LVL4X4matrix translationMatrix3D(LVLfloat3 f);

    LVL4X4matrix zRotationMatrix(LVLfloat z);
    LVL4X4matrix xRotationMatrix(LVLfloat x);
    LVL4X4matrix yRotationMatrix(LVLfloat y);

    LVL4X4matrix scalingMatrix2D(LVLfloat2 scale);
    LVL4X4matrix scalingMatrix3D(LVLfloat3 scale);

    LVL4X4matrix identityMatrix();

    //get a factorial value
    LVLfloat factorial(unsigned int digit);

    //get the power of a base value
    LVLfloat power(LVLfloat base, int exponant);


}


#endif