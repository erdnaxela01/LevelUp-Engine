#ifndef __SPRITE_H
#define __SPRITE_H

#include <d3d11.h>
#include "RenderObject.h"

namespace LevelUp
{

	struct VertexPos
	{
        LVLfloat3 pos;
        LVLfloat2 tex0;
	};


    //Draws a sprite on the screen does not work with camera, place with game object for extra functionality
    //Alex Sabourin April 2015
	class Sprite : public RenderObject
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


        //get the sprites width
		float getWidth(){ return m_width; }
        //set the spries width
		float getHeight(){ return m_height; }

		//display the sprite
		void render();
	protected:
		float m_width;
		float m_height;
		//set the vertext buffer
		virtual bool setVertexBuffer(VertexPos vertices[]);

		//sets the vertices
		virtual bool setVertices(float halfWidth, float halfHeight);

		VertexPos* getUnalteredVertices(float width, float height);
	private:
		ID3D11ShaderResourceView* m_colorMap;
		std::wstring m_fileName;
		bool m_dds;
	};
}

#endif

