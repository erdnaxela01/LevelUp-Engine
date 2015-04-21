#ifndef __DIRECTXMATHADAPTER_H
#define __DIRECTXMATHADAPTER_H

#include "MathAdapter.h"
#include "../MatrixContainer/MatrixContainer.h"
#include <DirectXMath.h>

namespace LevelUp
{
    struct LVL4X4matrix;

    //Math adapter to adapt to the directX math libary
    //Alex Sabourin April 2015

    class DirectXMathAdapter : public MathAdapter
    {
    public:
        void get4x4Matrix(LVL4X4matrix& m, MatrixContainer* con);
        void convertToLVLMatrix(LVL4X4matrix* mat, MatrixContainer* con);

    };
}
#endif