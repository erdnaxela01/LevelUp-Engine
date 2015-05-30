#include "PixelShader.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	PixelShader::PixelShader(std::wstring shaderName, std::string entryPoint, std::string level)
	{

		HRESULT d3dResult;
		ID3DBlob* psBuffer = 0;

		//compile the shader
		bool compileResult = ServiceLocator::getRenderService()->CompileD3DShader(shaderName, entryPoint, level, &psBuffer);

		if (!compileResult)
		{
			throw std::runtime_error("Could not load pixel shader");
		}

		//create the pixel shader
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(), 0, &m_solidColorPS);

		psBuffer->Release();

		if (FAILED(d3dResult))
		{
			throw std::runtime_error("could not create pixel shader");
		}
	}
	PixelShader::~PixelShader()
	{
		if (m_solidColorPS) m_solidColorPS->Release();
		m_solidColorPS = nullptr;
	}
	void PixelShader::setActiveShader()
	{
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
		context->PSSetShader(m_solidColorPS, 0, 0);
	}
}