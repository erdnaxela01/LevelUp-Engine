#include "Shape.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{

	Shape::Shape(LVLfloat4 color)
	{
		m_color = color;
	}
	Shape::~Shape()
	{

	}
	void Shape::setAlpha(float a)
	{
		a = MathHelper::Clamp(a, 0.0f, 1.0f);
		m_color.w = a;
		m_verticesAreDirty = true;
	}
	float Shape::getAlpha()
	{
		return m_color.z;
	}
	void Shape::setColor(LVLfloat3 c)
	{
		m_color.x = c.x;
		m_color.y = c.y;
		m_color.z = c.z;
		m_verticesAreDirty = true;
	}

	bool Shape::setVertexBuffer(ColorVertexPos vertices[], int num)
	{
		//set the vertex decription
		D3D11_BUFFER_DESC vertexDesc;
		SecureZeroMemory(&vertexDesc, sizeof(vertexDesc));
		vertexDesc.Usage = D3D11_USAGE_DYNAMIC;
		vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		vertexDesc.ByteWidth = sizeof(ColorVertexPos) * num;

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

}