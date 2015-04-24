#include "DirectXMathAdapter.h"
#include "../LevelUpMath.h"

namespace LevelUp
{
    void DirectXMathAdapter::get4x4Matrix(LVL4X4matrix& m, MatrixContainer* con)
    {
        //replace all the data
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                (*con).setFloatAt(r,c,m[r][c]);
            }
        }

    }
    void DirectXMathAdapter::convertToLVLMatrix(LVL4X4matrix* mat, MatrixContainer* con)
    {
        //creplace all the data
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                (*mat)[r][c] = con->getFloatAt(r, c).x;
            }
        }
    }
}