#ifndef __RENDERER_H
#define __RENDERER_H

#include <DirectXMath.h>
#include <d3d11.h>
#include <string>

namespace LevelUp
{
    //rendering service, will try to make more abstract in order to be able to change the renderer in the future
    //Alex Sabourin
	class Renderer
	{
	public:
		virtual void beginRender() = 0;
		virtual void finishRender() = 0;
		virtual ID3D11Device* getDevice() = 0;
		virtual ID3D11DeviceContext* getContext() = 0;
		virtual DirectX::XMMATRIX getVPMatrix() = 0;
		virtual void setVPMatrix(const DirectX::XMMATRIX &vp) = 0;
		virtual bool CompileD3DShader(std::wstring filePath, std::string entry, std::string shaderModel, ID3DBlob** buffer) = 0;

	};
}


#endif