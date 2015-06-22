#include "Rectangle.h"
#include "../Core/StandardTemplates.h"
#include "../Core/GameSprite.h"
#include "../Services/Math/MathFunctions.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	Rectangle::Rectangle(LVLfloat4 color, float width, float height) : m_width(width), m_height(height), Shape(color)
	{
        //load the rectangles content
		loadContent();
        //make a new gamesprite
        //set the initial position
		setPosition(0.0f, 0.0f);

		m_verticesAreDirty = true;
	}
	Rectangle::~Rectangle()
	{
        //unload all the content
		unloadContent();
	}

	bool Rectangle::loadContent()
	{
        //get the device
		APT::WeakPointer<ID3D11Device> device = ServiceLocator::getRenderService()->getDevice();

        //set up the color layout
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		m_vertexShader.setPtr(new VertexShader(L"SolidColorShader.fx", "VS_Main", "vs_4_0", solidColorLayout, ARRAYSIZE(solidColorLayout), &m_inputLayout.getPtrRef()));

		m_pixelShader.setPtr(new PixelShader(L"SolidColorShader.fx", "PS_Main", "ps_4_0"));
		


		bool result = setConstantBuffer();

		if (!result)
		{
			
			return result;
		}

		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;
		m_verticesAreDirty = true;
		ColorVertexPos* vertices = getVertices(halfWidth, halfHeight);
		//set the vertec buffer
		setVertexBuffer(vertices, 6);
		delete[] vertices;
		return true;
	}
	void Rectangle::unloadContent()
	{
        //release all the pointer
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
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		//
  //      //set the shaders

		m_vertexShader->setActiveShader();
		m_pixelShader->setActiveShader();

		context->IASetInputLayout(m_inputLayout.getPtr());

		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer.getPtrRef(), &stride, &offset);
		//
		//sprite specific
		//
		//sprite specific
		setMatrix();

        //draw the rectangle
		context->Draw(6, 0);
	}

	void Rectangle::resetVertices()
	{
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		//create a vector of the vertecx

		//set the vertec buffer
		float halfHeight = m_height / 2.0f;
		float halfWidth = m_width / 2.0f;
		ColorVertexPos* vertices = getVertices(halfWidth, halfHeight);

		D3D11_MAPPED_SUBRESOURCE mappedResource;
		ColorVertexPos* p;

		context->Map(m_vertexBuffer.getPtr(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

		p = (ColorVertexPos*)mappedResource.pData;

		memcpy(p, (void*)vertices, (sizeof(ColorVertexPos) * 6));
		context->Unmap(m_vertexBuffer.getPtr(), 0);

		delete[] vertices;

	}
	void Rectangle::setRect(LVLrect r)
	{
		m_sprite.setPosition(LVLfloat2((r.left + r.right)*0.5f, (r.bot + r.top)*0.5f));
		m_width = (r.right - m_sprite.getPosition().x) * 2;
		m_height = (r.top - m_sprite.getPosition().y) * 2;
		m_verticesAreDirty = true;
	}

	ColorVertexPos* Rectangle::getVertices(float halfWidth, float halfHeight)
	{
		ColorVertexPos* vert = new ColorVertexPos[6];
		vert[0] = { LVLfloat3(halfWidth, halfHeight, 1.0f), m_color };
		vert[1] = { LVLfloat3(halfWidth, -halfHeight, 1.0f), m_color };
		vert[2] = { LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color };

		vert[3] = { LVLfloat3(-halfWidth, -halfHeight, 1.0f), m_color };
		vert[4] = { LVLfloat3(-halfWidth, halfHeight, 1.0f), m_color };
		vert[5] = { LVLfloat3(halfWidth, halfHeight, 1.0f), m_color };
		return vert;
	}

}