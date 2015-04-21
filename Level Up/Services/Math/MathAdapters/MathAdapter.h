#ifndef __MATHADAPTER_H
#define __MATHADAPTER_H

#include <DirectXMath.h>
#include "../MatrixContainer/MatrixContainer.h"

namespace LevelUp
{
    struct LVL4X4matrix;

    //Math adapter to contain ion the service locator
    //Alex Sabourin
    class MathAdapter
    {
    public:
        //tried to have it polymorphic without having to cast however the only way to have an adaptor that works will be to add these functions
        //and have them do nothing in the future. Thought of void pointers but thats a bad idea

        //FIXED IT
        virtual void get4x4Matrix(LVL4X4matrix& m, MatrixContainer* con) = 0;
        virtual void convertToLVLMatrix(LVL4X4matrix* mat, MatrixContainer* con) = 0;
    };
}


#endif