#ifndef __GAME_BASE_H
#define __GAME_BASE_H
#include "Dx11Base.h"
#include "../Services/Renderer.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <d3d11.h>
class Game;

namespace LevelUp
{
	class RenderEngine final :
		public Dx11Base, public Renderer
	{
	public:
		virtual bool loadContent();
		virtual void unloadContent();

		virtual void update(float dt);
        //tells the render that i can start rendering
		virtual void beginRender();
		//display on screen
        void finishRender();

        //get direct x specific things
		ID3D11Device* getDevice();
		ID3D11DeviceContext* getContext();
        //get matrices
		DirectX::XMMATRIX getVPMatrix();
		void setVPMatrix(const DirectX::XMMATRIX &vp);
        //shutdown render engine - MUST be shutdown
		void shutdown();

        //compil the shaders
		bool CompileD3DShader(std::wstring filePath, string entry, string shaderModel, ID3DBlob** buffer);

		RenderEngine();
		~RenderEngine() {};

	private:

		ID3D11SamplerState* m_colorMapSampler;
		ID3D11BlendState* m_alphaBlendState;
		static DirectX::XMMATRIX m_vpMatrix;

	};
}
#endif

