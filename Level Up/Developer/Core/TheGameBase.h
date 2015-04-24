#ifndef __GAME_BASE_H
#define __GAME_BASE_H
#include "Dx11Base.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <d3d11.h>
class Game;

namespace LevelUp
{
	class TheGameBase final :
		public Dx11Base
	{
	public:
		virtual bool loadContent();
		virtual void unloadContent();

		virtual void update(float dt);
		virtual void render();
		//display on screen
		void present();
		//singleton
		static TheGameBase* getInstance();
		ID3D11Device* getDevice();
		ID3D11DeviceContext* getContext();
		DirectX::XMMATRIX getVPMatrix();
		void setVPMatrix(const DirectX::XMMATRIX &vp);
		void shutdown();

	private:

		ID3D11SamplerState* m_colorMapSampler;
		ID3D11BlendState* m_alphaBlendState;
		static DirectX::XMMATRIX m_vpMatrix;

		static TheGameBase* m_base;

		TheGameBase();
		TheGameBase(TheGameBase& e) {};
		TheGameBase& operator= (TheGameBase& rhs) { return rhs; }

	};
}
#endif

