#include "PixelShader.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	PixelShader::PixelShader(std::wstring shaderName, std::string entryPoint, std::string level)
	{

		m_solidColorPS.setDeleteFunc([](ID3D11PixelShader*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});
		HRESULT d3dResult;
		APT::StrongPointer<ID3DBlob> psBuffer = 0;
		psBuffer.setDeleteFunc([](ID3DBlob*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});

		//compile the shader
		bool compileResult = ServiceLocator::getRenderService()->CompileD3DShader(shaderName, entryPoint, level, &psBuffer.getPtrRef());

		if (!compileResult)
		{
			throw std::runtime_error("Could not load pixel shader");
		}

		//create the pixel shader
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(), 0, &m_solidColorPS.getPtrRef());

		psBuffer.clear();

		if (FAILED(d3dResult))
		{
			throw std::runtime_error("could not create pixel shader");
		}
	}
	PixelShader::~PixelShader()
	{
	}
	void PixelShader::setActiveShader()
	{
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		context->PSSetShader(m_solidColorPS.getPtr(), 0, 0);
	}
}