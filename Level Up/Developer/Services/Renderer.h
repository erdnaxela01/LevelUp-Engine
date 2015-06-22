#ifndef __RENDERER_H
#define __RENDERER_H

#include <DirectXMath.h>
#include <d3d11.h>
#include <string>
#include "Math\DataTypes.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{

    class Viewport;
    //rendering service, will try to make more abstract in order to be able to change the renderer in the future
    //Alex Sabourin
	class Renderer
	{
	public:
		Renderer() {};
		virtual ~Renderer() {};

		virtual void beginRender() = 0;
		virtual void finishRender() = 0;
        //needs abstraction
		virtual APT::WeakPointer<ID3D11Device> getDevice() const = 0;
        //needs abstraction
		virtual APT::WeakPointer<ID3D11DeviceContext> getContext() const = 0;
        //get a view point matrix
		virtual LVL4X4matrix getVPMatrix() const = 0; //
        //set a view point matrix
        virtual void setVPMatrix(const LVL4X4matrix &vp) = 0; //
        //compile a shader
		virtual bool CompileD3DShader(std::wstring filePath, std::string entry, std::string shaderModel, ID3DBlob** buffer) = 0;
        //factory to produce a viewport
        virtual Viewport* produceViewport() = 0;
		//set the screen to full screen
		virtual void setFullScreenMode(bool b) = 0;
		//resize buffer
		virtual void resizeBuffer(LVLfloat2 size) = 0;
		//set the background color
		virtual void setBgColor(LVLfloat3 color) = 0;
		//get the background color
		virtual LVLfloat3 getBgColor() = 0;


	};
}


#endif