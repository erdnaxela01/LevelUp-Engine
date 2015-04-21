#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include <d3d11.h>
#include <DirectXMath.h>
#include "../Services/Math/LevelUpMath.h"

namespace LevelUp
{
	struct ColorVertexPos
	{
        LVLfloat3 pos;
        LVLfloat4 color;
	};

	class GameSprite;

    //draws a rectangle on the screen with the specified values
    //Alex Sabourin April 2015
	class Rectangle
	{
	public:
        Rectangle(LVLfloat4 color, float width, float height);
		virtual ~Rectangle();
		bool loadContent();
		void unloadContent();
        LVLfloat2 getPosition();
		void setPosition(float x, float y);
		void setScale(float x, float y);
		void render();
        void setAlpha(float a);
        float getAlpha();
		bool setVertexBuffer(ColorVertexPos vertices[]);

		float getWidth(){ return m_width; }
		float getHeight(){ return m_height; }
	private:
		ID3D11Buffer* m_vertexBuffer;
		ID3D11ShaderResourceView* m_colorMap;
		GameSprite* m_sprite;
		ID3D11VertexShader* m_solidColorVS;
		ID3D11PixelShader* m_solidColorPS;

		ID3D11InputLayout* m_inputLayout;
		float m_width;
		float m_height;
		ID3D11Buffer* m_mvpCB;
        LVLfloat4 m_color;
        float m_alpha;
	};
}

#endif