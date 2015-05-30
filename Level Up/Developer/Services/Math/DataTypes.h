#ifndef __LEVELUPMATH_H
#define __LEVELUPMATH_H

namespace LevelUp
{
    /*
    All the LevelUp Engine data types used to clear dependencies from other math libaries and for easier porting in the future
    Alex Sabourin April 2015
    
    */


    struct LVLfloat
    {
        float x;
        LVLfloat operator* (const LVLfloat &rhs);
        LVLfloat operator- (const LVLfloat &rhs);
        LVLfloat operator+ (const LVLfloat &rhs);
        LVLfloat operator/ (const LVLfloat &rhs);
        void operator= (const float &rhs);
        void operator*= (const float &rhs);
        void operator/= (const float &rhs);
        void operator+= (const float &rhs);
        void operator-= (const float &rhs);
        void operator*= (const LVLfloat &rhs);
        void operator-= (const LVLfloat &rhs);
        void operator+= (const LVLfloat &rhs);
        void operator/= (const LVLfloat &rhs);
        LVLfloat(float tx);
        LVLfloat();
		~LVLfloat() {};
    };

    struct LVLfloat2
    {
        float x;
        float y;
        LVLfloat2 operator* (const LVLfloat2 &rhs);
        LVLfloat2 operator- (const LVLfloat2 &rhs);
        LVLfloat2 operator+ (const LVLfloat2 &rhs);
        void operator*= (const float &rhs);
        void operator/= (const float &rhs);
        void operator+= (const LVLfloat2 &rhs);
        void operator-= (const LVLfloat2 &rhs);
        LVLfloat2 operator*(const float &rhs);
        LVLfloat2 operator/ (const float &rhs);
        LVLfloat2(float tx, float ty);
        LVLfloat2();
		~LVLfloat2() {};

    };

    struct LVLfloat3
    {
        float x;
        float y;
        float z;
        LVLfloat3 operator* (const LVLfloat3 &rhs);
        LVLfloat3 operator- (const LVLfloat3 &rhs);
        LVLfloat3 operator+ (const LVLfloat3 &rhs);
        LVLfloat3(float tx, float ty, float tz);
        LVLfloat3();
		~LVLfloat3() {};
    };

    struct LVLfloat4
    {
        float x;
        float y;
        float z;
        float w;
        LVLfloat4 operator* (const LVLfloat4 &rhs);
        LVLfloat4 operator- (const LVLfloat4 &rhs);
        LVLfloat4 operator+ (const LVLfloat4 &rhs);
        LVLfloat4(float tx, float ty, float tz, float tw);
        LVLfloat4();
		~LVLfloat4() {};
    };

    struct LVLmatrixRow4
    {
        float row[4];
        LVLmatrixRow4 operator* (LVLmatrixRow4 &rhs);
        LVLmatrixRow4 operator- (LVLmatrixRow4 &rhs);
        LVLmatrixRow4 operator+ (LVLmatrixRow4 &rhs);
        float& operator[](const int &index);
        LVLmatrixRow4();
		~LVLmatrixRow4() {};
    };
    
    struct LVL4X4matrix
    {
        LVLmatrixRow4 mat[4];
        LVL4X4matrix operator* (LVL4X4matrix &rhs);
        LVL4X4matrix operator+ (LVL4X4matrix &rhs);
        LVL4X4matrix operator- (LVL4X4matrix &rhs);
        LVLmatrixRow4& operator[](const int &index);
		LVL4X4matrix();
		~LVL4X4matrix() {};
    };

	struct LVLrect
	{
		float top;
		float bot;
		float left;
		float right;

		void operator=(const LVLrect& rhs);
		LVLrect(float l = 0.0f, float b = 0.0f, float r = 0.0f, float t = 0.0f);
		~LVLrect() {};
	};




}


#endif