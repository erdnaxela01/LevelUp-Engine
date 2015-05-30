#ifndef __COLOR_H
#define __COLOR_H

#include "../Services/Math/DataTypes.h"

namespace LevelUp
{
	//static class to get preset colors
	//Alex Sabourin May 2015
    class Color
    {
    public:
        static LVLfloat3 getAqua();
        static LVLfloat3 getForestGreen();
		static LVLfloat3 getBeige();
		static LVLfloat3 getChocolate();
		static LVLfloat3 getCyan();
		static LVLfloat3 getDeepPink();
		static LVLfloat3 getFuchsia();
		static LVLfloat3 getGold();
		static LVLfloat3 getHotPink();
		static LVLfloat3 getLavender();
		static LVLfloat3 getLawnGreen();
		static LVLfloat3 getLime();
		static LVLfloat3 getMagenta();
		static LVLfloat3 getNavy();
		static LVLfloat3 getOrange();
		static LVLfloat3 getRed();
		static LVLfloat3 getYellow();
		static LVLfloat3 getBlue();
		static LVLfloat3 getGreen();
        static LVLfloat3 convertFromHex(float red, float green, float blue);
    };
}


#endif