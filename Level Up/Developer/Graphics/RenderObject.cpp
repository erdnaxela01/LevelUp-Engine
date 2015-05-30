#include "RenderObject.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	RenderObject::~RenderObject()
	{
		unloadContent();
	}

	void RenderObject::unloadContent()
	{
		if (m_vertexBuffer) m_vertexBuffer->Release();
		if (m_mvpCB) m_mvpCB->Release();
		if (m_inputLayout) m_inputLayout->Release();
		if (m_vertexShader) delete m_vertexShader;
		if (m_pixelShader) delete m_pixelShader;
		m_pixelShader = nullptr;
		m_vertexShader = nullptr;
		m_vertexBuffer = nullptr;
		m_mvpCB = nullptr;
		m_inputLayout = nullptr;
	}
	void RenderObject::setPosition(float x, float y)
	{
		//set the position
		LVLfloat2 sprite1Pos(x, y);
		m_sprite.setPosition(sprite1Pos);

	}
	LVLfloat2  RenderObject::getPosition()
	{
		//get the sprites position
		LVLfloat2 sprite1Pos = m_sprite.getPosition();
		return sprite1Pos;
	}
	void RenderObject::setScale(float x, float y)
	{
		m_sprite.setScale(LVLfloat2(x, y));


	}


	void RenderObject::rotate(float angle)
	{
		m_sprite.setRotation(angle);
	}

	void RenderObject::setMatrix()
	{
		ID3D11DeviceContext* context = ServiceLocator::getRenderService()->getContext();
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
	}

	bool RenderObject::setConstantBuffer()
	{
		ID3D11Device* device = ServiceLocator::getRenderService()->getDevice();
		//create a constant buffer description and set the model view projection buffer for the sprite
		D3D11_BUFFER_DESC constDesc;
		SecureZeroMemory(&constDesc, sizeof(constDesc));
		constDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constDesc.ByteWidth = sizeof(DirectX::XMMATRIX);
		constDesc.Usage = D3D11_USAGE_DEFAULT;
		HRESULT d3dResult;
		d3dResult = device->CreateBuffer(&constDesc, 0, &m_mvpCB);

		if (FAILED(d3dResult))
		{
			return false;
		}
		return true;
	}

}