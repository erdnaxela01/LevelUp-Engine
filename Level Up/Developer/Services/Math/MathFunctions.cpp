#include "MathFunctions.h"
#include <math.h>

namespace LevelUp
{
    LVL4X4matrix translationMatrix2D(LVLfloat2 f)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[3][0] = f.x;
        mat[3][1] = f.y;
        mat[3][2] = 0.0f;
        return mat;
    }
    LVL4X4matrix translationMatrix3D(LVLfloat3 f)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[3][0] = f.x;
        mat[3][1] = f.y;
        mat[3][2] = f.z;
        return mat;
    }

    LVL4X4matrix zRotationMatrix(LVLfloat z)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = z.x;
        mat[0][0] = cosf(angle);
        mat[0][1] = sinf(angle);
        mat[1][0] = -sinf(angle);
        mat[1][1] = cos(angle);
        return mat;
    }
    LVL4X4matrix xRotationMatrix(LVLfloat x)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = x.x;
        mat[1][1] = cosf(angle);
        mat[1][2] = sinf(angle);
        mat[2][1] = -sinf(angle);
        mat[2][2] = cos(angle);
        return mat;
    }
    LVL4X4matrix yRotationMatrix(LVLfloat y)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = y.x;
        mat[0][0] = cosf(angle);
        mat[0][2] = sinf(angle);
        mat[2][0] = -sinf(angle);
        mat[2][2] = cos(angle);
        return mat;
    }

    LVL4X4matrix scalingMatrix2D(LVLfloat2 scale)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[0][0] = scale.x;
        mat[1][1] = scale.y;
        return mat;
    }
    LVL4X4matrix scalingMatrix3D(LVLfloat3 scale)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[0][0] = scale.x;
        mat[1][1] = scale.y;
        mat[2][2] = scale.z;
        return mat;
    }

    LVL4X4matrix identityMatrix()
    {
        LVL4X4matrix mat;
        for (int i = 0; i < 4; i++)
        {
            mat[i][i] = 1.0f;
        }
        return mat;
    }

    LVLfloat factorial(unsigned int digit)
    {
        LVLfloat total = digit;
        if (digit == 1)
        {
            return 1;
        }
        for (int i = digit - 1; i > 1; i--)
        {
            total *= i;
        }
        return total;
    }
    LVLfloat power(LVLfloat base, int exponant)
    {
        LVLfloat total = 0.0f;
        if (exponant == 0)
        {
            return 1.0f;
        }
        else if (exponant == 1)
        {
            return base;
        }
        total = base;
        for (int i = 1; i < exponant; i++)
        {
            total *= base;
        }
        return total;
    }
}