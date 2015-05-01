#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include <d3d11.h>
#include <DirectXMath.h>
#include "../Services/Math/LevelUpMath.h"
#include "../Core/GameSprite.h"

namespace LevelUp
{
	struct ColorVertexPos
	{
        LVLfloat3 pos;
        LVLfloat4 color;
	};


    //draws a rectangle on the screen with the specified values
    //Alex Sabourin April 2015
	class Rectangle
	{
	public:
        Rectangle(LVLfloat4 color, float width, float height);
		virtual ~Rectangle();
        //load the rectangles content
		bool loadContent();
        //unload the rectangles content
		void unloadContent();
        //get the rectangles position
        LVLfloat2 getPosition();
        //set the rectangles position
		void setPosition(float x, float y);
        //set the rectangles scale
		void setScale(float x, float y);
        //render the rectangle
		void render();
        //set the rectangles alpha
        void setAlpha(float a);
        //get the rectangles alpha
        float getAlpha();
        //set the rectangles vertex buffer
		bool setVertexBuffer(ColorVertexPos vertices[]);
        //get the width of the rectangle
		float getWidth(){ return m_width; }
        //get the rectangles height
		float getHeight(){ return m_height; }
        //set the angle of the sprite
        void setAngle(float a);
        //set the color of the rectangle
        void setColor(LVLfloat3 c);
		//set the rectangle
		void setRect(LVLrect r);
	private:
		ID3D11Buffer* m_vertexBuffer;
		ID3D11ShaderResourceView* m_colorMap;
		GameSprite m_sprite;
		ID3D11VertexShader* m_solidColorVS;
		ID3D11PixelShader* m_solidColorPS;

		ID3D11InputLayout* m_inputLayout;
		float m_width;
		float m_height;
		ID3D11Buffer* m_mvpCB;
        LVLfloat4 m_color;
        float m_alpha;

		void resetVertices();

		bool m_verticesAreDirty;
	};
}

#endif