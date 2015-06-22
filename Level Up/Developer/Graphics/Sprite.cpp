
#include "Sprite.h"
#include "../Core/StandardTemplates.h"
#include "../Core/GameSprite.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/LevelUpMath.h"
#include "TextureManager.h"
#include <Windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <string>


namespace LevelUp
{

	//declaration of statics
	TextureManager Sprite::m_manager;

	Sprite::Sprite(bool dds) : m_dds(dds)
	{
		m_colorMap.setDeleteFunc([](ID3D11ShaderResourceView*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});
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

		HRESULT d3dResult;

        //create the vertex buffer
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		m_vertexShader.setPtr(new VertexShader(L"SpriteShader.fx", "VS_Main", "vs_4_0", solidColorLayout, ARRAYSIZE(solidColorLayout), &m_inputLayout.getPtrRef()));
		m_pixelShader.setPtr(new PixelShader(L"SpriteShader.fx", "PS_Main", "ps_4_0"));


		bool result = setConstantBuffer();
		if (!result)
		{
			return result;
		}

		m_colorMap = m_manager.getTexture(m_fileName, m_dds);
		//load sprite starts
		ID3D11Resource* colorTex;
		m_colorMap.getter()->GetResource(&colorTex);

        //set the color description
		D3D11_TEXTURE2D_DESC colorTexDesc;
		((ID3D11Texture2D*)colorTex)->GetDesc(&colorTexDesc);
		colorTex->Release();

        //get the width, height and set the halfwidth and height
		m_width = (float)colorTexDesc.Width;
		float halfWidth = m_width * 0.5f;
		m_height = (float)colorTexDesc.Height;
		float halfHeight = m_height * 0.5f;

		result = setVertices(halfWidth, halfHeight);
		if (!result)
		{
			return false;
		}
		return true;
	}

	void Sprite::unloadContent()
	{
        //release all the com objects
		//releases the texture if its the last one from the texture manager
	}

	void Sprite::render()
	{
		//sprite specific
		unsigned int stride = sizeof(VertexPos);
		unsigned int offset = 0;
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		//set the input layout
		
		m_vertexShader->setActiveShader();
		m_pixelShader->setActiveShader();
		context->IASetInputLayout(m_inputLayout.getPtr());
		//set it as a triangle list
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer.getPtrRef(), &stride, &offset);

		//
		//sprite specific
		context->PSSetShaderResources(0, 1, &m_colorMap.getPtrRef());
		//
		//sprite specific
		setMatrix();
        //draw the sprite
		context->Draw(6, 0);
		//
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
		d3dResult = ServiceLocator::getRenderService()->getDevice()->CreateBuffer(&vertexDesc, &resourceData, &m_vertexBuffer.getPtrRef());

		if (FAILED(d3dResult))
		{
			MessageBox(0, L"Failed to create vertex buffer!", L"Error creating vertex buffer", MB_OK);
			return false;
		}
		return true;
	}
	bool  Sprite::setVertices(float halfWidth, float halfHeight)
	{
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		//set the vertices
		VertexPos* vert = getUnalteredVertices(halfWidth * 2, halfHeight * 2);
		
		setVertexBuffer(vert);

		delete[] vert;

		return true;
	}

	VertexPos* Sprite::getUnalteredVertices(float width, float height)
	{
		float halfWidth = width * 0.5f;
		float halfHeight = height * 0.5f;

		VertexPos* vert = new VertexPos[6];
		vert[0] = { LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(1.0f, 0.0f) };
		vert[1] = { LVLfloat3(halfWidth, -halfHeight, 1.0f), LVLfloat2(1.0f, 1.0f) };
		vert[2] = { LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(0.0f, 1.0f) };
		vert[3] = { LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(0.0f, 1.0f) };
		vert[4] = { LVLfloat3(-halfWidth, halfHeight, 1.0f), LVLfloat2(0.0f, 0.0f) };
		vert[5] = { LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(1.0f, 0.0f) };

		return vert;
	}
}