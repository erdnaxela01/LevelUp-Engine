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

        //load the sprites content
		bool loadContent();
        //unload the sprites content
		void unloadContent();

        //get the sprites position
        LVLfloat2 getPosition();
        //set the sprites positions
		void setPosition(float x, float y);
        //set the sprites scale
		void setScale(float x, float y);

        //get the sprites width
		float getWidth(){ return m_width; }
        //set the spries width
		float getHeight(){ return m_height; }

        //roate the sprite
		void rotate(float angle);
		//display the sprite
		void render();
        //set the vertext buffer
		bool setVertexBuffer(VertexPos vertices[]);
		
		//sets the vertices
		virtual bool setVertices(float halfWidth, float halfHeight);
	protected:
		float m_width;
		float m_height;
	private:
		ID3D11Buffer* m_vertexBuffer;
		ID3D11ShaderResourceView* m_colorMap;
		GameSprite m_sprite;
		ID3D11VertexShader* m_solidColorVS;
		ID3D11PixelShader* m_solidColorPS;

		ID3D11InputLayout* m_inputLayout;
		std::wstring m_fileName;
		bool m_dds;
		ID3D11Buffer* m_mvpCB;
	};
}

#endif

