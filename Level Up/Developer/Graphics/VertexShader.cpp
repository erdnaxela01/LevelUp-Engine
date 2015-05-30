#include "VertexShader.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	VertexShader::VertexShader(std::wstring shaderName, std::string entryPoint, std::string level, D3D11_INPUT_ELEMENT_DESC solidColorLayout[],int arraySize, ID3D11InputLayout** inputLayout)
	{
		HRESULT d3dResult;
		//create the vertex buffer
		ID3DBlob* vsBuffer = 0;
		bool compileResult;
		compileResult = ServiceLocator::getRenderService()->CompileD3DShader(shaderName, entryPoint, level, &vsBuffer);
		if (!compileResult)
		{
			throw std::runtime_error("Couldn't load shader");
		}


		//create the vertex shader
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &m_solidColorVS);

		if (FAILED(d3dResult))
		{
			if (vsBuffer)
			{
				vsBuffer->Release();

			}
			throw std::runtime_error("Failes to load vertex buffer");
		}


		unsigned int totalLayoutElements = arraySize;

		//create the input layout

		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateInputLayout(solidColorLayout, totalLayoutElements, vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), inputLayout);



		if (FAILED(d3dResult))
		{
			throw std::runtime_error("failed to create input layout");
		}
		vsBuffer->Release();
	}
	VertexShader::~VertexShader()
	{
		if (m_solidColorVS) m_solidColorVS->Release();
		m_solidColorVS = nullptr;
	}
	void VertexShader::setActiveShader()
	{
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
		context->VSSetShader(m_solidColorVS, 0, 0);
	}
}