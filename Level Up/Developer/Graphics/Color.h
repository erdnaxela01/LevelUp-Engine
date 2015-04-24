#ifndef __COLOR_H
#define __COLOR_H

#include "../Services/Math/DataTypes.h"

namespace LevelUp
{
    class Color
    {
    public:
        static LVLfloat3 getAqua();
        static LVLfloat3 getForestGreen();
        static LVLfloat3 convertFromHex(float red, float green, float blue);

    };
}


#endif