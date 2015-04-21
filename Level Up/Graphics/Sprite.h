#ifndef __SPRITE_H
#define __SPRITE_H

#include "../Core/GameSprite.h"
#include <d3d11.h>


namespace LevelUp
{

	struct VertexPos
	{
        LVLfloat3 pos;
        LVLfloat2 tex0;
	};


    //Draws a sprite on the screen
    //Alex Sabourin April 2015
	class Sprite
	{
	public:
		Sprite(bool dds = false);
		virtual ~Sprite();

		//initializes the sprite and its values
		bool initialize(std::wstring fileName);

		bool loadContent();
		void unloadContent();

        LVLfloat2 getPosition();
		void setPosition(float x, float y);
		void setScale(float x, float y);

		float getWidth(){ return m_width; }
		float getHeight(){ return m_height; }

		void rotate(float angle);
		//display the sprite
		void render();

		bool setVertexBuffer(VertexPos vertices[]);

	private:
		ID3D11Buffer* m_vertexBuffer;
		ID3D11ShaderResourceView* m_colorMap;
		GameSprite m_sprite;
		ID3D11VertexShader* m_solidColorVS;
		ID3D11PixelShader* m_solidColorPS;

		ID3D11InputLayout* m_inputLayout;
		std::wstring m_fileName;
		float m_width;
		float m_height;
		bool m_dds;
		ID3D11Buffer* m_mvpCB;
	};
}

#endif

