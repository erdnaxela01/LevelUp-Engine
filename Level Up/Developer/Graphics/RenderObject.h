#ifndef __RENDEROBJECT_H
#define __RENDEROBJECT_H

#include <d3d11.h>
#include "../Core/GameSprite.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	class RenderObject
	{
	public:
		RenderObject() {};
		virtual ~RenderObject();
		virtual bool loadContent() = 0;
		virtual void unloadContent();
		//get the sprites position
		LVLfloat2 getPosition();
		//set the sprites positions
		void setPosition(float x, float y);
		//set the sprites scale
		void setScale(float x, float y);

		//roate the sprite
		void rotate(float angle);

		//pure virtual
		virtual void render() = 0;
	protected:
		GameSprite m_sprite;
		APT::StrongPointer<ID3D11Buffer> m_vertexBuffer;
		APT::StrongPointer<VertexShader> m_vertexShader;
		APT::StrongPointer<PixelShader> m_pixelShader;

		APT::StrongPointer<ID3D11InputLayout> m_inputLayout;
		APT::StrongPointer<ID3D11Buffer> m_mvpCB;

		void setMatrix();

		bool setConstantBuffer();

	};
}

#endif