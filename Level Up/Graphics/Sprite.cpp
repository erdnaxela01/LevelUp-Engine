
#include "Sprite.h"
#include "../Core/StandardTemplates.h"
#include "../Core/GameSprite.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/LevelUpMath.h"
#include <Windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <string>
#include <DDSTextureLoader.h>
#include <WICTextureLoader.h>

namespace LevelUp
{
	Sprite::Sprite(bool dds) : m_dds(dds)
	{

	}


	Sprite::~Sprite()
	{
        //unload all the sprite content
		unloadContent();
	}


	bool Sprite::loadContent()
	{
		//get dds

        //get the device
		ID3D11Device* device = ServiceLocator::getRenderService()->getDevice();

		HRESULT d3dResult;

        //create the vertex buffer
		ID3DBlob* vsBuffer = 0;
		bool compileResult;
		compileResult =ServiceLocator::getRenderService()->CompileD3DShader(L"../Shaders/SpriteShader.fx", "VS_Main", "vs_4_0", &vsBuffer);
		if (!compileResult)
		{
			MessageBox(0, L"Error loading vertex shader!", L"Compile error", MB_OK);
			return false;
		}


        //create the vertex shader
		d3dResult = device->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &m_solidColorVS);

		if (FAILED(d3dResult))
		{
			if (vsBuffer)
			{
				vsBuffer->Release();

			}
			return false;
		}

        //set the coor layout
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};


		unsigned int totalLayoutElements = ARRAYSIZE(solidColorLayout);

        //create the input layout
		d3dResult = device->CreateInputLayout(solidColorLayout, totalLayoutElements, vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), &m_inputLayout);

		if (FAILED(d3dResult))
		{
			return false;
		}

		ID3DBlob* psBuffer = 0;

        //compile the shader
		compileResult = ServiceLocator::getRenderService()->CompileD3DShader(L"../Shaders/SpriteShader.fx", "PS_Main", "ps_4_0", &psBuffer);

		if (!compileResult)
		{
			MessageBox(0, L"Error loading pixel shader", L"Compile Error", MB_OK);
			return false;
		}

        //create the pixel shader
		d3dResult = device->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(), 0, &m_solidColorPS);

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
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateBuffer(&constDesc, 0, &m_mvpCB);

		if (FAILED(d3dResult))
		{
			return false;
		}

		//get the image in the assets folder
		if (m_dds == true)
		{
			d3dResult = DirectX::CreateDDSTextureFromFile(device, m_fileName.c_str(), nullptr, &m_colorMap);
		}
		else
		{
			d3dResult = DirectX::CreateWICTextureFromFile(device, m_fileName.c_str(), nullptr, &m_colorMap);
		}
		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Failed to load texture", L"Error", MB_OK);
			return false;
		}
		//load sprite starts
		ID3D11Resource* colorTex;
		m_colorMap->GetResource(&colorTex);

        //set the color description
		D3D11_TEXTURE2D_DESC colorTexDesc;
		((ID3D11Texture2D*)colorTex)->GetDesc(&colorTexDesc);
		colorTex->Release();

        //get the width, height and set the halfwidth and height
		m_width = (float)colorTexDesc.Width;
		float halfWidth = m_width * 0.5f;
		m_height = (float)colorTexDesc.Height;
		float halfHeight = m_height * 0.5f;

        //set the vertices
		VertexPos vertices[] =
		{
            { LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(1.0f, 0.0f) },
            { LVLfloat3(halfWidth, -halfHeight, 1.0f), LVLfloat2(1.0f, 1.0f) },
            { LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(0.0f, 1.0f) },

            { LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(0.0f, 1.0f) },
            { LVLfloat3(-halfWidth, halfHeight, 1.0f), LVLfloat2(0.0f, 0.0f) },
            { LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(1.0f, 0.0f) }
		};


		bool result = setVertexBuffer(vertices);
		if (!result)
		{
			return false;
		}

		//load sprite ends
		//
		return true;
	}

	void Sprite::unloadContent()
	{
        //release all the com objects
		if (m_colorMap) m_colorMap->Release();
		if (m_vertexBuffer) m_vertexBuffer->Release();
		if (m_mvpCB) m_mvpCB->Release();
		if (m_solidColorVS) m_solidColorVS->Release();
		if (m_solidColorPS) m_solidColorPS->Release();
		if (m_inputLayout) m_inputLayout->Release();
		m_colorMap = nullptr;
		m_vertexBuffer = nullptr;
		m_mvpCB = nullptr;
		m_solidColorVS = nullptr;
		m_solidColorPS = nullptr;
		m_inputLayout = nullptr;
	}

	void Sprite::render()
	{
		//sprite specific
		unsigned int stride = sizeof(VertexPos);
		unsigned int offset = 0;
		//
        //get the context
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();

        //set the shaders
		context->VSSetShader(m_solidColorVS, 0, 0);
		context->PSSetShader(m_solidColorPS, 0, 0);

        //set the input layout
		context->IASetInputLayout(m_inputLayout);

        //set it as a triangle list
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
		//
		//sprite specific
		context->PSSetShaderResources(0, 1, &m_colorMap);
		//
		//sprite specific
        //get the world matrix
        DirectX::XMMATRIX world;
        ServiceLocator::getMathAdapter()->get4x4Matrix(m_sprite.GetWorldMatrix(), &DirectXMatrixContainer(&world));
        DirectX::XMMATRIX vp;
        ServiceLocator::getMathAdapter()->get4x4Matrix(ServiceLocator::getRenderService()->getVPMatrix(), &DirectXMatrixContainer(&vp));
		DirectX::XMMATRIX mvp = DirectX::XMMatrixMultiply(world, vp);
		mvp = DirectX::XMMatrixTranspose(mvp);
		//

		//sprite specific
		context->UpdateSubresource(m_mvpCB, 0, 0, &mvp, 0, 0);
		context->VSSetConstantBuffers(0, 1, &m_mvpCB);

        //draw the sprite
		context->Draw(6, 0);
		//
	}

	void Sprite::setPosition(float x, float y)
	{
        //set the position
		LVLfloat2 sprite1Pos(x, y);
		m_sprite.setPosition(sprite1Pos);

	}

	bool Sprite::initialize(std::wstring fileName)
	{
        //create the sprite and load the content
		m_fileName = L"../Assets/Images/" + fileName;
		bool result = true;
		result = loadContent();

		setPosition(0.0f, 0.0f);
		return result;
	}

	void Sprite::setScale(float x, float y)
	{
        m_sprite.setScale(LVLfloat2(x, y));


	}

    LVLfloat2 Sprite::getPosition()
	{
        //get the sprites position
		LVLfloat2 sprite1Pos = m_sprite.getPosition();
		return sprite1Pos;
	}

	void Sprite::rotate(float angle)
	{
		m_sprite.setRotation(angle);
	}

	bool Sprite::setVertexBuffer(VertexPos vertices[])
	{
        //create the vertex description
		D3D11_BUFFER_DESC vertexDesc;
		SecureZeroMemory(&vertexDesc, sizeof(vertexDesc));
		vertexDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexDesc.ByteWidth = sizeof(VertexPos) * 6;

        //set the ressource data
		D3D11_SUBRESOURCE_DATA resourceData;
		SecureZeroMemory(&resourceData, sizeof(resourceData));
		resourceData.pSysMem = vertices;
		HRESULT d3dResult;
        //create the constant buffer
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateBuffer(&vertexDesc, &resourceData, &m_vertexBuffer);

		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Failed to create vertex buffer!", L"Error creating vertex buffer", MB_OK);
			return false;
		}
        return true;
	}
}