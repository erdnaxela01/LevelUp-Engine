#include "Color.h"

namespace LevelUp
{
    LVLfloat3 Color::getAqua()
    {
        return LVLfloat3(0.0f, 1.0f, 1.0f);
    }
    LVLfloat3 Color::getForestGreen()
    {
        return convertFromHex(0x23, 0x8E, 0x23);
    }
    LVLfloat3 Color::convertFromHex(float red, float green, float blue)
    {
        return LVLfloat3(red / 0xFF, green / 0xFF, blue / 0xFF);
    }

}