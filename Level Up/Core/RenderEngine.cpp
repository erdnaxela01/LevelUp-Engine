#include "RenderEngine.h"
#include "../Game/Game.h"
#include "../Core/StandardTemplates.h"
#include "../Services/WindowScreen.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/LevelUpMath.h"
#include "DirectXViewport.h"

namespace LevelUp
{

	RenderEngine::RenderEngine()
	{
	}

	bool RenderEngine::loadContent()
	{
        //set up the color mpa description
		D3D11_SAMPLER_DESC colorMapDesc;
		SecureZeroMemory(&colorMapDesc, sizeof(colorMapDesc));
		colorMapDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		colorMapDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		colorMapDesc.MaxLOD = D3D11_FLOAT32_MAX;

        //create the sampler state using the color map dessc
		HRESULT d3dResult = m_d3dDevice->CreateSamplerState(&colorMapDesc, &m_colorMapSampler);

		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Fail to create color map sampler state!", L"Color Map error", MB_OK);
			return false;
		}

        //set up the view projefction matrix for the first time
		ScreenSize* window = ServiceLocator::getScreenSizeService();
		DirectX::XMMATRIX view = DirectX::XMMatrixIdentity();
		DirectX::XMMATRIX projection = DirectX::XMMatrixOrthographicOffCenterLH(0.0f, window->getScreenSize().x, 0.0f, window->getScreenSize().y, 0.1f, 100.0f);

        ServiceLocator::getMathAdapter()->convertToLVLMatrix(&(m_vpMatrix), &DirectXMatrixContainer(&DirectX::XMMatrixMultiply(view, projection)));

        //set up the blend description for color blending
		D3D11_BLEND_DESC blendDesc;
		SecureZeroMemory(&blendDesc, sizeof(blendDesc));
		blendDesc.RenderTarget[0].BlendEnable = TRUE;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_INV_DEST_ALPHA;
		blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = 0x0F;


        //set the blend factor
		float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

        //create the blend state and set it to the output merger
		m_d3dDevice->CreateBlendState(&blendDesc, &m_alphaBlendState);
		m_d3dContext->OMSetBlendState(m_alphaBlendState, blendFactor, 0xFFFFFFFF);

        //set up the intial viewport
		D3D11_VIEWPORT viewport;
		viewport.Width = static_cast<float>(window->getScreenSize().x);
		viewport.Height = static_cast<float>(window->getScreenSize().y);
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		m_d3dContext->RSSetViewports(1, &viewport);


		return true;

	}

	void RenderEngine::unloadContent()
	{
        //release all the pointers
		if (m_colorMapSampler)m_colorMapSampler->Release();
		if (m_alphaBlendState) m_alphaBlendState->Release();

		m_colorMapSampler = nullptr;
		m_alphaBlendState = nullptr;

	}

	void RenderEngine::beginRender()
	{
        //tell the engine to start rendering and to draw the background
		if (m_d3dContext == 0)
		{
			return;
		}

		float clearColor[4] = { 0.30f, 0.0f, 0.30f, 1.0f };
		m_d3dContext->ClearRenderTargetView(m_backBufferTarget, clearColor);

		m_d3dContext->PSSetSamplers(0, 1, &m_colorMapSampler);

	}


	void RenderEngine::finishRender()
	{
        //present the rendering
		m_swapChain->Present(0, 0);
	}
	void RenderEngine::shutdown()
	{
        //unload all the content and shutdown the  base class
		unloadContent();
		Dx11Base::shutdown();
	}

	ID3D11Device* RenderEngine::getDevice()
	{
		return m_d3dDevice;
	}

	ID3D11DeviceContext* RenderEngine::getContext()
	{
		return m_d3dContext;
	}

    LVL4X4matrix RenderEngine::getVPMatrix()
	{
		return m_vpMatrix;
	}

    void RenderEngine::setVPMatrix(const LVL4X4matrix &vp)
	{
		m_vpMatrix = vp;
	}
	

	bool RenderEngine::CompileD3DShader(std::wstring filePath, std::string entry, std::string shaderModel, ID3DBlob** buffer)
	{
        //set tje shaderflags
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

        //debugging code
#if defined (DEBUG) || defined(_DEBUS)
		shaderFlags |= D3DCompile_DEBUG;
#endif

		ID3DBlob* errorBuffer = 0;
		HRESULT result;

        //use the compile from file function to load a shader into the buffer
		result = D3DCompileFromFile(filePath.c_str(), 0, 0, entry.c_str(), shaderModel.c_str(), shaderFlags, 0, buffer, &errorBuffer);
		if (FAILED(result))
		{
			if (errorBuffer != 0)
			{
				OutputDebugString((LPCWSTR)errorBuffer->GetBufferPointer());
				errorBuffer->Release();
			}
			return false;
		}

		if (errorBuffer != 0)
		{
			errorBuffer->Release();
		}
		return true;
	}

    DirectXViewport* RenderEngine::produceViewport()
    {
        //factory to produce a viewport
        DirectXViewport* v = new DirectXViewport();
        return v;
    }
}