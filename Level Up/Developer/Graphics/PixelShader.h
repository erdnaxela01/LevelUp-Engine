#ifndef __PIXELSHADER_H
#define __PIXELSHADER_H

#include "Shader.h"
#include <d3d11.h>
#include <string>
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"
namespace LevelUp
{
	class PixelShader
	{
	public:
		PixelShader(std::wstring shaderName, std::string entryPoint, std::string level);
		virtual ~PixelShader();
		void setActiveShader();
	private:
		APT::StrongPointer<ID3D11PixelShader> m_solidColorPS;
	};
}

#endif