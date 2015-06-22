#include "RenderObject.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
	RenderObject::~RenderObject()
	{
		unloadContent();
		m_vertexBuffer.setDeleteFunc([](ID3D11Buffer*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});

		m_mvpCB.setDeleteFunc([](ID3D11Buffer*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});

		m_inputLayout.setDeleteFunc([](ID3D11InputLayout*& p)
		{
			if (p) p->Release();
			p = nullptr;
		});
	}

	void RenderObject::unloadContent()
	{
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
		APT::WeakPointer<ID3D11DeviceContext> context = ServiceLocator::getRenderService()->getContext();
		//get the world matrix
		DirectX::XMMATRIX world;
		ServiceLocator::getMathAdapter()->get4x4Matrix(m_sprite.GetWorldMatrix(), &DirectXMatrixContainer(&world));
		DirectX::XMMATRIX vp;
		ServiceLocator::getMathAdapter()->get4x4Matrix(ServiceLocator::getRenderService()->getVPMatrix(), &DirectXMatrixContainer(&vp));
		DirectX::XMMATRIX mvp = DirectX::XMMatrixMultiply(world, vp);
		mvp = DirectX::XMMatrixTranspose(mvp);
		//

		//sprite specific
		context->UpdateSubresource(m_mvpCB.getPtr(), 0, 0, &mvp, 0, 0);
		context->VSSetConstantBuffers(0, 1, &m_mvpCB.getPtrRef());
	}

	bool RenderObject::setConstantBuffer()
	{
		APT::WeakPointer<ID3D11Device> device = ServiceLocator::getRenderService()->getDevice();
		//create a constant buffer description and set the model view projection buffer for the sprite
		D3D11_BUFFER_DESC constDesc;
		SecureZeroMemory(&constDesc, sizeof(constDesc));
		constDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constDesc.ByteWidth = sizeof(DirectX::XMMATRIX);
		constDesc.Usage = D3D11_USAGE_DEFAULT;
		HRESULT d3dResult;
		d3dResult = device->CreateBuffer(&constDesc, 0, &m_mvpCB.getPtrRef());

		if (FAILED(d3dResult))
		{
			return false;
		}
		return true;
	}

}