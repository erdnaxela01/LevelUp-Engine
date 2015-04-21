#include "TheGameBase.h"
#include "../Game/Game.h"
#include "../Core/StandardTemplates.h"
#include "../Services/WindowScreen.h"

namespace LevelUp
{
	DirectX::XMMATRIX TheGameBase::m_vpMatrix = {};
	TheGameBase* TheGameBase::m_base = nullptr;

	TheGameBase::TheGameBase()
	{
	}

	bool TheGameBase::loadContent()
	{

		D3D11_SAMPLER_DESC colorMapDesc;
		SecureZeroMemory(&colorMapDesc, sizeof(colorMapDesc));
		colorMapDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		colorMapDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		colorMapDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		colorMapDesc.MaxLOD = D3D11_FLOAT32_MAX;

		HRESULT d3dResult = m_d3dDevice->CreateSamplerState(&colorMapDesc, &m_colorMapSampler);

		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Fail to create color map sampler state!", L"Color Map error", MB_OK);
			return false;
		}



		DirectX::XMMATRIX view = DirectX::XMMatrixIdentity();
		DirectX::XMMATRIX projection = DirectX::XMMatrixOrthographicOffCenterLH(0.0f, WindowScreen::getScreenSize().x, 0.0f, WindowScreen::getScreenSize().y, 0.1f, 100.0f);

		(m_vpMatrix) = DirectX::XMMatrixMultiply(view, projection);

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


		float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

		m_d3dDevice->CreateBlendState(&blendDesc, &m_alphaBlendState);
		m_d3dContext->OMSetBlendState(m_alphaBlendState, blendFactor, 0xFFFFFFFF);

		D3D11_VIEWPORT viewport;
		viewport.Width = static_cast<float>(WindowScreen::getScreenSize().x);
		viewport.Height = static_cast<float>(WindowScreen::getScreenSize().y);
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		m_d3dContext->RSSetViewports(1, &viewport);


		return true;

	}

	void TheGameBase::unloadContent()
	{
		if (m_colorMapSampler)m_colorMapSampler->Release();
		if (m_alphaBlendState) m_alphaBlendState->Release();

		m_colorMapSampler = nullptr;
		m_alphaBlendState = nullptr;

	}

	void TheGameBase::render()
	{
		if (m_d3dContext == 0)
		{
			return;
		}

		float clearColor[4] = { 0.30f, 0.0f, 0.30f, 1.0f };
		m_d3dContext->ClearRenderTargetView(m_backBufferTarget, clearColor);

		m_d3dContext->PSSetSamplers(0, 1, &m_colorMapSampler);

	}

	void TheGameBase::update(float dt)
	{
	}

	void TheGameBase::present()
	{
		m_swapChain->Present(0, 0);
	}


	TheGameBase* TheGameBase::getInstance()
	{
		if (m_base == nullptr)
		{
			m_base = new TheGameBase();
		}
		return m_base;
	}

	void TheGameBase::shutdown()
	{
		unloadContent();
		Dx11Base::shutdown();
		SafeDelete(m_base);
	}

	ID3D11Device* TheGameBase::getDevice()
	{
		return m_d3dDevice;
	}

	ID3D11DeviceContext* TheGameBase::getContext()
	{
		return m_d3dContext;
	}

	DirectX::XMMATRIX TheGameBase::getVPMatrix()
	{
		return m_vpMatrix;
	}

	void TheGameBase::setVPMatrix(const DirectX::XMMATRIX &vp)
	{
		m_vpMatrix = vp;
	}
}