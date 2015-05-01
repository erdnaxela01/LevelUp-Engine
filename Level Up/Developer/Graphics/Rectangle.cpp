#include "Rectangle.h"
#include "../Core/StandardTemplates.h"
#include "../Core/GameSprite.h"
#include "../Services/Math/MathFunctions.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	Rectangle::Rectangle(LVLfloat4 color, float width, float height) : m_color(color), m_width(width), m_height(height), m_verticesAreDirty(true)
	{
        //load the rectangles content
		loadContent();
        //make a new gamesprite
        //set the initial position
		setPosition(0.0f, 0.0f);
	}
	Rectangle::~Rectangle()
	{
        //unload all the content
		unloadContent();
	}

	bool Rectangle::loadContent()
	{
        //get the device
		ID3D11Device* device = ServiceLocator::getRenderService()->getDevice();
		ID3DBlob* vsBuffer = 0;

        //compile the shader
		bool compileResult = ServiceLocator::getRenderService()->CompileD3DShader(L"SolidColorShader.fx", "VS_Main", "vs_4_0", &vsBuffer);

		if (compileResult == false)
		{
			MessageBox(0, L"Error loading vertex shader!", L"Compile Error", MB_OK);
			return false;
		}

		HRESULT d3dResult;
        //create the vertex shader
		d3dResult = device->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &m_solidColorVS);

		if (FAILED(d3dResult))
		{
			if (vsBuffer)
				vsBuffer->Release();

			return false;
		}

        //set up the color layout
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};


		unsigned int totalLayoutElements = ARRAYSIZE(solidColorLayout);

		d3dResult = device->CreateInputLayout(solidColorLayout, totalLayoutElements,
			vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), &m_inputLayout);

        //release the vertex shader buffer
		vsBuffer->Release();

		if (FAILED(d3dResult))
		{
			return false;
		}

        //create a pixel shader buffer
		ID3DBlob* psBuffer = 0;

		compileResult = ServiceLocator::getRenderService()->CompileD3DShader(L"SolidColorShader.fx", "PS_Main", "ps_4_0", &psBuffer);

		if (compileResult == false)
		{
			MessageBox(0, L"Error loading pixel shader!", L"Compile Error", MB_OK);
			return false;
		}

        //create the pixel shader
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

		m_verticesAreDirty = true;
		return true;
	}
	void Rectangle::unloadContent()
	{
        //release all the pointer
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
	}
    LVLfloat2 Rectangle::getPosition()
	{
        //get the sprites positon
        LVLfloat2 sprite1Pos = m_sprite.getPosition();
		return sprite1Pos;
	}
	void Rectangle::setPosition(float x, float y)
	{
        //set the sprites position
        LVLfloat2 sprite1Pos(x, y);
		m_sprite.setPosition(sprite1Pos);
	}
	void Rectangle::setScale(float x, float y)
	{
        //set the rectangles scale
        m_sprite.setScale(LVLfloat2(x, y));
	}

	void Rectangle::render()
	{//sprite specific
		if (m_verticesAreDirty)
		{
			resetVertices();
			m_verticesAreDirty = false;
		}
		unsigned int stride = sizeof(ColorVertexPos);
		unsigned int offset = 0;

        //get5 the device contexzt
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
		//
        //set the shaders

		context->VSSetShader(m_solidColorVS, 0, 0);
		context->PSSetShader(m_solidColorPS, 0, 0);

		context->IASetInputLayout(m_inputLayout);

		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
		//
		//sprite specific
		//
		//sprite specific
        //get the world matrix
		LVL4X4matrix world = m_sprite.GetWorldMatrix();
        DirectX::XMMATRIX tempWorld;
        ServiceLocator::getMathAdapter()->get4x4Matrix(world, &DirectXMatrixContainer(&tempWorld));
        DirectX::XMMATRIX vp;
        ServiceLocator::getMathAdapter()->get4x4Matrix(ServiceLocator::getRenderService()->getVPMatrix(), &DirectXMatrixContainer(&vp));
		DirectX::XMMATRIX mvp = DirectX::XMMatrixMultiply(tempWorld, vp);
		mvp = DirectX::XMMatrixTranspose(mvp);
		//

		//sprite specific
        //update the subresource and set the constant buffer
		context->UpdateSubresource(m_mvpCB, 0, 0, &mvp, 0, 0);
		context->VSSetConstantBuffers(0, 1, &m_mvpCB);

        //draw the rectangle
		context->Draw(6, 0);
	}

	bool Rectangle::setVertexBuffer(ColorVertexPos vertices[])
	{
        //set the vertex decription
		D3D11_BUFFER_DESC vertexDesc;
		SecureZeroMemory(&vertexDesc, sizeof(vertexDesc));
		vertexDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexDesc.ByteWidth = sizeof(ColorVertexPos) * 6;

        //set the resource data
		D3D11_SUBRESOURCE_DATA resourceData;
		SecureZeroMemory(&resourceData, sizeof(resourceData));
		resourceData.pSysMem = vertices;
		HRESULT d3dResult;
        //create the buffer
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
        a = MathHelper::Clamp(a, 0.0f, 1.0f);
        m_color.w = a;
		m_verticesAreDirty = true;
    }
    float Rectangle::getAlpha()
    {
        return m_color.z;
    }
    void Rectangle::setColor(LVLfloat3 c)
    {
        m_color.x = c.x;
        m_color.y = c.y;
        m_color.z = c.z;
		m_verticesAreDirty = true;
    }
    void Rectangle::setAngle(float a)
    {
        m_sprite.setRotation(a);
    }

	void Rectangle::resetVertices()
	{
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;
		//create a vector of the vertecx
		ColorVertexPos vertices[] =
		{
			{ LVLfloat3(halfWidth, halfHeight, 1.0f), m_color },
			{ LVLfloat3(halfWidth, -halfHeight, 1.0f), m_color },
			{ LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color },

			{ LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color },
			{ LVLfloat3(-halfWidth, halfHeight, 1.0f), m_color },
			{ LVLfloat3(halfWidth, halfHeight, 1.0f), m_color }
		};

		//set the vertec buffer
		setVertexBuffer(vertices);
	}
	void Rectangle::setRect(LVLrect r)
	{
		m_sprite.setPosition(LVLfloat2((r.left + r.right)*0.5f, (r.bot + r.top)*0.5f));
		m_width = (r.right - m_sprite.getPosition().x) * 2;
		m_height = (r.top - m_sprite.getPosition().y) * 2;
		m_verticesAreDirty = true;
	}

}