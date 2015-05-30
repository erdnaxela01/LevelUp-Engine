#include "Circle.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/MathFunctions.h"

#include <vector>

namespace LevelUp
{
	Circle::Circle(LVLfloat4 color, float radius) :m_radius(radius), Shape(color)
	{
		loadContent();

		setPosition(0.0f, 0.0f);

		m_verticesAreDirty = true;
	}
	Circle::~Circle()
	{
		unloadContent();
	}

	bool Circle::loadContent()
	{
		//get the device
		ID3D11Device* device = ServiceLocator::getRenderService()->getDevice();

		//set up the color layout
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		m_vertexShader = new VertexShader(L"SolidColorShader.fx", "VS_Main", "vs_4_0", solidColorLayout, ARRAYSIZE(solidColorLayout), &m_inputLayout);

		m_pixelShader = new PixelShader(L"SolidColorShader.fx", "PS_Main", "ps_4_0");



		bool result = setConstantBuffer();

		if (!result)
		{

			return result;
		}

		m_verticesAreDirty = true;
		ColorVertexPos* vertices = getVertices(m_radius);
		//set the vertec buffer
		setVertexBuffer(vertices, NUM_OF_SIDES * 3);

		delete[] vertices;
		return true;
	}
	void Circle::unloadContent()
	{

	}

	void Circle::render()
	{
		//sprite specific
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
		//      //set the shaders

		m_vertexShader->setActiveShader();
		m_pixelShader->setActiveShader();

		context->IASetInputLayout(m_inputLayout);

		//sprite specific code
		context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
		//
		//sprite specific
		//
		//sprite specific
		setMatrix();

		//draw the rectangle
		context->Draw(NUM_OF_SIDES * 3, 0);
	}

	float Circle::getRadius() const
	{
		return m_radius;
	}
	void Circle::setRadius(float r)
	{
		m_radius = r;
	}
	ColorVertexPos* Circle::getVertices(float radius)
	{
		ColorVertexPos* vertices = new ColorVertexPos[NUM_OF_SIDES * 3];
		float perc = NUM_OF_SIDES / 360;
		int count = 0;
		for (int i = 1; i <= NUM_OF_SIDES; i++)
		{
			vertices[count++] = { LVLfloat3(0, 0, 1.0f), m_color };
			vertices[count++] = { LVLfloat3(std::cos(MathHelper::DegreesToRadians(i / perc)) * m_radius, std::sin(MathHelper::DegreesToRadians(i / perc)) * m_radius, 1.0f), m_color };
			vertices[count++] = { LVLfloat3(std::cos(MathHelper::DegreesToRadians((i - 1) / perc)) * m_radius, std::sin(MathHelper::DegreesToRadians((i - 1) / perc)) * m_radius, 1.0f), m_color };
		}
		return vertices;
	}

	void Circle::resetVertices()
	{
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
		//create a vector of the vertecx

		//set the vertec buffer
		ColorVertexPos* vertices = getVertices(m_radius);

		D3D11_MAPPED_SUBRESOURCE mappedResource;
		ColorVertexPos* p;

		context->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

		p = (ColorVertexPos*)mappedResource.pData;

		memcpy(p, (void*)vertices, (sizeof(ColorVertexPos) *  NUM_OF_SIDES * 3));
		context->Unmap(m_vertexBuffer, 0);

		delete[] vertices;

	}
}