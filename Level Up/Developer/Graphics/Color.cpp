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
	LVLfloat3 Color::getBeige()
	{
		return convertFromHex(0xF5, 0xF5, 0xDC);
	}
	LVLfloat3 Color::getChocolate()
	{
		return convertFromHex(0xD2, 0x69, 0x1E);
	}
	LVLfloat3 Color::getCyan()
	{
		return convertFromHex(0x00, 0xFF, 0xFF);
	}
	LVLfloat3 Color::getDeepPink()
	{
		return convertFromHex(0xFF, 0x14, 0x93);
	}
	LVLfloat3 Color::getFuchsia()
	{
		return convertFromHex(0xFF, 0x00, 0xFF);
	}
	LVLfloat3 Color::getGold()
	{
		return convertFromHex(0xFF, 0xD7, 0x00);
	}
	LVLfloat3 Color::getHotPink()
	{
		return convertFromHex(0xFF, 0x69, 0xB4);
	}
	LVLfloat3 Color::getLavender()
	{
		return convertFromHex(0xE6, 0xE6, 0xFA);
	}
	LVLfloat3 Color::getLawnGreen()
	{
		return convertFromHex(0x7C, 0xFC, 0x00);
	}
	LVLfloat3 Color::getLime()
	{
		return convertFromHex(0x00, 0xFF, 0x00);
	}
	LVLfloat3 Color::getMagenta()
	{
		return convertFromHex(0xFF, 0x00, 0xFF);
	}
	LVLfloat3 Color::getNavy()
	{
		return convertFromHex(0x00, 0x00, 0x80);
	}
	LVLfloat3 Color::getOrange()
	{
		return convertFromHex(0xFF, 0x45, 0x00);
	}
	LVLfloat3 Color::getRed()
	{
		return convertFromHex(0xFF, 0x00, 0x00);
	}
	LVLfloat3 Color::getYellow()
	{
		return convertFromHex(0xFF, 0xFF, 0x00);
	}
	LVLfloat3 Color::getBlue()
	{
		return convertFromHex(0x00, 0x00, 0xFF);
	}
	LVLfloat3 Color::getGreen()
	{
		return convertFromHex(0x00, 0xFF, 0x00);
	}

}