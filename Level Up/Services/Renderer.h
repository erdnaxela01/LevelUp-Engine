#ifndef __RENDERER_H
#define __RENDERER_H

#include <DirectXMath.h>
#include <d3d11.h>
#include <string>
#include "Math\DataTypes.h"

namespace LevelUp
{

    class Viewport;
    //rendering service, will try to make more abstract in order to be able to change the renderer in the future
    //Alex Sabourin
	class Renderer
	{
	public:
		virtual void beginRender() = 0;
		virtual void finishRender() = 0;
        //needs abstraction
		virtual ID3D11Device* getDevice() = 0;
        //needs abstraction
		virtual ID3D11DeviceContext* getContext() = 0;
        //get a view point matrix
		virtual LVL4X4matrix getVPMatrix() = 0; //
        //set a view point matrix
        virtual void setVPMatrix(const LVL4X4matrix &vp) = 0; //
        //compile a shader
		virtual bool CompileD3DShader(std::wstring filePath, std::string entry, std::string shaderModel, ID3DBlob** buffer) = 0;
        //factory to produce a viewport
        virtual Viewport* produceViewport() = 0;

	};
}


#endif