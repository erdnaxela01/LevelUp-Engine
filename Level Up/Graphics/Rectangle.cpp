#include "Rectangle.h"
#include "../Core/StandardTemplates.h"
#include "../Core/GameSprite.h"

#include "../Services/ServiceLocator.h"

namespace LevelUp
{
    Rectangle::Rectangle(LVLfloat4 color, float width, float height) : m_color(color), m_width(width), m_height(height)
	{
		loadContent();
		m_sprite = new GameSprite();
		setPosition(0.0f, 0.0f);
	}
	Rectangle::~Rectangle()
	{
		unloadContent();
	}

	bool Rectangle::loadContent()
	{

		ID3D11Device* device = ServiceLocator::getRenderService()->getDevice();
		ID3DBlob* vsBuffer = 0;

		bool compileResult = ServiceLocator::getRenderService()->CompileD3DShader(L"../Shaders/SolidColorShader.fx", "VS_Main", "vs_4_0", &vsBuffer);

		if (compileResult == false)
		{
			MessageBox(0, L"Error loading vertex shader!", L"Compile Error", MB_OK);
			return false;
		}

		HRESULT d3dResult;

		d3dResult = device->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &m_solidColorVS);

		if (FAILED(d3dResult))
		{
			if (vsBuffer)
				vsBuffer->Release();

			return false;
		}

		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		unsigned int totalLayoutElements = ARRAYSIZE(solidColorLayout);

		d3dResult = device->CreateInputLayout(solidColorLayout, totalLayoutElements,
			vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), &m_inputLayout);

		vsBuffer->Release();

		if (FAILED(d3dResult))
		{
			return false;
		}

		ID3DBlob* psBuffer = 0;

		compileResult = ServiceLocator::getRenderService()->CompileD3DShader(L"../Shaders/SolidColorShader.fx", "PS_Main", "ps_4_0", &psBuffer);

		if (compileResult == false)
		{
			MessageBox(0, L"Error loading pixel shader!", L"Compile Error", MB_OK);
			return false;
		}

		d3dResult = device->CreatePixelShader(psBuffer->GetBufferPointer(),
			psBuffer->GetBufferSize(), 0, &m_solidColorPS);

		psBuffer->Release();

		if (FAILED(d3dResult))
		{
			return false;
		}


		//create a constant buffer description and set the model view projection buffer for the sprite
		D3D11_BUFFER_DESC constDesc;
		SecureZeroMemory(&constDesc, sizeof(constDesc));
		constDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constDesc.ByteWidth = sizeof(DirectX::XMMATRIX);
		constDesc.Usage = D3D11_USAGE_DEFAULT;
		d3dResult = device->CreateBuffer(&constDesc, 0, &m_mvpCB);

		if (FAILED(d3dResult))
		{
			return false;
		}


		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;
		ColorVertexPos vertices[] =
		{
            { LVLfloat3(halfWidth, halfHeight, 1.0f), m_color },
            { LVLfloat3(halfWidth, -halfHeight, 1.0f), m_color },
            { LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color },

            { LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color },
            { LVLfloat3(-halfWidth, halfHeight, 1.0f), m_color },
            { LVLfloat3(halfWidth, halfHeight, 1.0f), m_color }
		};

		bool result = setVertexBuffer(vertices);
		if (!result)
		{
			return false;
		}
		return true;
	}
	void Rectangle::unloadContent()
	{
		if (m_vertexBuffer) m_vertexBuffer->Release();
		if (m_mvpCB) m_mvpCB->Release();
		if (m_solidColorVS) m_solidColorVS->Release();
		if (m_solidColorPS) m_solidColorPS->Release();
		if (m_inputLayout) m_inputLayout->Release();
		m_vertexBuffer = nullptr;
		m_mvpCB = nullptr;
		m_solidColorVS = nullptr;
		m_solidColorPS = nullptr;
		m_inputLayout = nullptr;
		SafeDelete(m_sprite);
	}
    LVLfloat2 Rectangle::getPosition()
	{
        LVLfloat2 sprite1Pos = m_sprite->getPosition();
		return sprite1Pos;
	}
	void Rectangle::setPosition(float x, float y)
	{
        LVLfloat2 sprite1Pos(x, y);
		m_sprite->setPosition(sprite1Pos);
	}
	void Rectangle::setScale(float x, float y)
	{
        m_sprite->setScale(LVLfloat2(x, y));
	}

	void Rectangle::render()
	{//sprite specific
		unsigned int stride = sizeof(ColorVertexPos);
		unsigned int offset = 0;

		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
		//
		context->VSSetShader(m_solidColorVS, 0, 0);
		context->PSSetShader(m_solidColorPS, 0, 0);

		context->IASetInputLayout(m_inputLayout);

		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
		//
		//sprite specific
		//
		//sprite specific
		LVL4X4matrix world = m_sprite->GetWorldMatrix();
        DirectX::XMMATRIX tempWorld;
        ServiceLocator::getMathAdapter()->get4x4Matrix(world, &DirectXMatrixContainer(&tempWorld));
		DirectX::XMMATRIX mvp = DirectX::XMMatrixMultiply(tempWorld, (ServiceLocator::getRenderService()->getVPMatrix()));
		mvp = DirectX::XMMatrixTranspose(mvp);
		//

		//sprite specific
		context->UpdateSubresource(m_mvpCB, 0, 0, &mvp, 0, 0);
		context->VSSetConstantBuffers(0, 1, &m_mvpCB);

		context->Draw(6, 0);
	}

	bool Rectangle::setVertexBuffer(ColorVertexPos vertices[])
	{
		D3D11_BUFFER_DESC vertexDesc;
		SecureZeroMemory(&vertexDesc, sizeof(vertexDesc));
		vertexDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexDesc.ByteWidth = sizeof(ColorVertexPos) * 6;

		D3D11_SUBRESOURCE_DATA resourceData;
		SecureZeroMemory(&resourceData, sizeof(resourceData));
		resourceData.pSysMem = vertices;
		HRESULT d3dResult;
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateBuffer(&vertexDesc, &resourceData, &m_vertexBuffer);

		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Failed to create vertex buffer!", L"Error creating vertex buffer", MB_OK);
			return false;
		}
        return true;
	}
    void Rectangle::setAlpha(float a)
    {
        m_color.z = a;
    }
    float Rectangle::getAlpha()
    {
        return m_color.z;
    }
}