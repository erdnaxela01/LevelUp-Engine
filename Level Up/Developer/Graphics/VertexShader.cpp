#include "VertexShader.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	VertexShader::VertexShader(std::wstring shaderName, std::string entryPoint, std::string level, D3D11_INPUT_ELEMENT_DESC solidColorLayout[],int arraySize, ID3D11InputLayout** inputLayout)
	{
		m_solidColorVS.setDeleteFunc([](ID3D11VertexShader*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});
		HRESULT d3dResult;
		//create the vertex buffer
		APT::StrongPointer<ID3DBlob> vsBuffer = 0;
		vsBuffer.setDeleteFunc([](ID3DBlob*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});
		bool compileResult;
		compileResult = ServiceLocator::getRenderService()->CompileD3DShader(shaderName, entryPoint, level, &vsBuffer.getPtrRef());
		if (!compileResult)
		{
			throw std::runtime_error("Couldn't load shader");
		}


		//create the vertex shader
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &m_solidColorVS.getPtrRef());

		if (FAILED(d3dResult))
		{
			vsBuffer.clear();
			throw std::runtime_error("Failes to load vertex buffer");
		}


		unsigned int totalLayoutElements = arraySize;

		//create the input layout

		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateInputLayout(solidColorLayout, totalLayoutElements, vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), inputLayout);



		if (FAILED(d3dResult))
		{
			throw std::runtime_error("failed to create input layout");
		}
		vsBuffer.clear();
	}
	VertexShader::~VertexShader()
	{
	}
	void VertexShader::setActiveShader()
	{
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		context->VSSetShader(m_solidColorVS.getPtr(), 0, 0);
	}
}