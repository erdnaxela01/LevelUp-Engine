#include "LevelUpMath.h"

namespace LevelUp
{

    //LVLfloat
    LVLfloat::LVLfloat(float tx)
    {
        x = tx;
    }
    LVLfloat::LVLfloat()
    {
        x = 0.0f;
    }

    LVLfloat LVLfloat::operator* (const LVLfloat &rhs)
    {
        LVLfloat l;
        l.x = this->x * rhs.x;
        return l;
    }

    LVLfloat LVLfloat::operator- (const LVLfloat &rhs)
    {
        LVLfloat l;
        l.x = this->x - rhs.x;
        return l;
    }
    LVLfloat LVLfloat::operator+ (const LVLfloat &rhs)
    {
        LVLfloat l;
        l.x = this->x + rhs.x;
        return l;
    }
    LVLfloat LVLfloat::operator/ (const LVLfloat &rhs)
    {
        LVLfloat l;
        l.x = this->x / rhs.x;
        return l;
    }
    void LVLfloat::operator= (const float &rhs)
    {
        x = rhs;
    }

    void LVLfloat::operator*= (const float &rhs)
    {
        x *= rhs;
    }
    void LVLfloat::operator/= (const float &rhs)
    {
        x /= rhs;
    }
    void LVLfloat::operator+= (const float &rhs)
    {
        x += rhs;
    }
    void LVLfloat::operator-= (const float &rhs)
    {
        x -= rhs;
    }
    void LVLfloat::operator*= (const LVLfloat &rhs)
    {
        x *= rhs.x;
    }
    void LVLfloat::operator-= (const LVLfloat &rhs)
    {
        x -= rhs.x;
    }
    void LVLfloat::operator+= (const LVLfloat &rhs)
    {
        x += rhs.x;
    }
    void LVLfloat::operator/= (const LVLfloat &rhs)
    {
        x /= rhs.x;
    }


    LVLfloat2::LVLfloat2(float tx, float ty)
    {
        x = tx;
        y = ty;
    }
    LVLfloat2::LVLfloat2()
    {
        x = 0.0f;
        y = 0.0f;

    }

    LVLfloat2 LVLfloat2::operator* (const LVLfloat2 &rhs)
    {
        LVLfloat2 l;
        l.x = this->x * rhs.x;
        l.y = this->y * rhs.y;
        return l;
    }
    LVLfloat2 LVLfloat2::operator- (const LVLfloat2 &rhs)
    {
        LVLfloat2 l;
        l.x = this->x - rhs.x;
        l.y = this->y - rhs.y;
        return l;
    }
    LVLfloat2 LVLfloat2::operator+ (const LVLfloat2 &rhs)
    {
        LVLfloat2 l;
        l.x = this->x + rhs.x;
        l.y = this->y + rhs.y;
        return l;
    }



    LVLfloat3::LVLfloat3(float tx, float ty, float tz)
    {
        x = tx;
        y = ty;
        z = tz;
    }
    LVLfloat3::LVLfloat3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    LVLfloat3 LVLfloat3::operator* (const LVLfloat3 &rhs)
    {
        LVLfloat3 l;
        l.x = this->x * rhs.x;
        l.y = this->y * rhs.y;
        l.z = this->z * rhs.z;
        return l;
    }
    LVLfloat3 LVLfloat3::operator- (const LVLfloat3 &rhs)
    {
        LVLfloat3 l;
        l.x = this->x - rhs.x;
        l.y = this->y - rhs.y;
        l.z = this->z - rhs.z;
        return l;
    }
    LVLfloat3 LVLfloat3::operator+ (const LVLfloat3 &rhs)
    {
        LVLfloat3 l;
        l.x = this->x + rhs.x;
        l.y = this->y + rhs.y;
        l.z = this->z + rhs.z;
        return l;
    }


    LVLfloat4::LVLfloat4(float tx, float ty, float tz, float tw)
    {
        x = tx;
        y = ty;
        z = tz;
        w = tw;

    }
    LVLfloat4::LVLfloat4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    LVLfloat4 LVLfloat4::operator* (const LVLfloat4 &rhs)
    {
        LVLfloat4 l;
        l.x = this->x * rhs.x;
        l.y = this->y * rhs.y;
        l.z = this->z * rhs.z;
        l.w = this->w * rhs.w;
        return l;
    }
    LVLfloat4 LVLfloat4::operator- (const LVLfloat4 &rhs)
    {
        LVLfloat4 l;
        l.x = this->x - rhs.x;
        l.y = this->y - rhs.y;
        l.z = this->z - rhs.z;
        l.w = this->w - rhs.w;
        return l;
    }
    LVLfloat4 LVLfloat4::operator+ (const LVLfloat4 &rhs)
    {
        LVLfloat4 l;
        l.x = this->x + rhs.x;
        l.y = this->y + rhs.y;
        l.z = this->z + rhs.z;
        l.w = this->w + rhs.w;
        return l;
    }

    LVLmatrixRow4::LVLmatrixRow4()
    {
        for (int i = 0; i < 4; i++)
        {
            row[i] = 0.0f;
        }
    }

    float&  LVLmatrixRow4::operator[](const int &index)
    {
        return row[index];
    }

    LVLmatrixRow4 LVLmatrixRow4::operator* (LVLmatrixRow4 &rhs)
    {
        LVLmatrixRow4 l;
        l[0] = (*this)[0] * rhs[0];
        l[1] = (*this)[1] * rhs[1];
        l[2] = (*this)[2] * rhs[2];
        l[3] = (*this)[3] * rhs[3];
        return l;
    }
    LVLmatrixRow4 LVLmatrixRow4::operator- (LVLmatrixRow4 &rhs)
    {
        LVLmatrixRow4 l;
        l[0] = (*this)[0] - rhs[0];
        l[1] = (*this)[1] - rhs[1];
        l[2] = (*this)[2] - rhs[2];
        l[3] = (*this)[3] - rhs[3];
        return l;
    }
    LVLmatrixRow4 LVLmatrixRow4::operator+ (LVLmatrixRow4 &rhs)
    {
        LVLmatrixRow4 l;
        l[0] = (*this)[0] + rhs[0];
        l[1] = (*this)[1] + rhs[1];
        l[2] = (*this)[2] + rhs[2];
        l[3] = (*this)[3] + rhs[3];
        return l;
    }


    LVL4X4matrix::LVL4X4matrix()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                mat[i][j] = 0.0f;
            }
        }
    }

    LVLmatrixRow4& LVL4X4matrix::operator[](const int &index)
    {
        return mat[index];
    }


    LVL4X4matrix LVL4X4matrix::operator* (LVL4X4matrix &rhs)
    {
        LVL4X4matrix m;
        LVLmatrixRow4 left;
        LVLmatrixRow4 right;

        for (int j = 0; j < 4; j++)
        {
            left = (*this)[j];
            for (int i = 0; i < 4; i++)
            {
                right[0] = rhs[0][i];
                right[1] = rhs[1][i];
                right[2] = rhs[2][i];
                right[3] = rhs[3][i];

                m[j][i] = (left[0] * right[0]) + (left[1] * right[1]) + (left[2] * right[2]) + (left[3] * right[3]);
            }
        }
        return m;
        
    }
    LVL4X4matrix LVL4X4matrix::operator+ (LVL4X4matrix &rhs)
    {
        LVL4X4matrix m;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m.mat[i][j] = this->mat[i][j] + rhs.mat[i][j];
            }
        }
        return m;
    }
    LVL4X4matrix LVL4X4matrix::operator- (LVL4X4matrix &rhs)
    {
        LVL4X4matrix m;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m.mat[i][j] = this->mat[i][j] - rhs.mat[i][j];
            }
        }
        return m;
        return m;
    }

}