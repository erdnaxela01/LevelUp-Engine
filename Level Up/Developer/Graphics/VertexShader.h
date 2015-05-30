#ifndef __VERTEXSHADER_H
#define __VERTEXSHADER_H

#include "Shader.h"
#include <d3d11.h>
#include <string>
namespace LevelUp
{
	class VertexShader : public Shader
	{
	public:
		VertexShader(std::wstring shaderName,std::string entryPoint, std::string level, D3D11_INPUT_ELEMENT_DESC solidColorLayout[],int arraySize, ID3D11InputLayout** inputLayout);
		virtual ~VertexShader();
		void setActiveShader();
	private:
		ID3D11VertexShader* m_solidColorVS;
	};
}
#endif