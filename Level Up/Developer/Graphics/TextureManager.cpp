#include "TextureManager.h"
#include <DDSTextureLoader.h>
#include <WICTextureLoader.h>
#include "../Services/ServiceLocator.h"
namespace LevelUp
{
	APT::ChangePointer<ID3D11ShaderResourceView> TextureManager::getTexture(std::wstring texturePath, bool dds)
	{
		if (m_textures[{texturePath, dds}].getPtr() == nullptr)
		{
			HRESULT d3dResult;
			if (dds == true)
			{
				d3dResult = DirectX::CreateDDSTextureFromFile(ServiceLocator::getRenderService()->getDevice().getPtr(), texturePath.c_str(), nullptr, &m_textures[{texturePath, dds}].getPtrRef());
			}
			else
			{
				d3dResult = DirectX::CreateWICTextureFromFile(ServiceLocator::getRenderService()->getDevice().getPtr(), texturePath.c_str(), nullptr, &m_textures[{texturePath, dds}].getPtrRef());
			}
			if (FAILED(d3dResult))
			{
				MessageBox(0, L"Failed to load texture", L"Error", MB_OK);
				return false;
			}
			m_textures[{texturePath, dds}].setDeleteFunc([](ID3D11ShaderResourceView*& p)
			{
				if (p) p->Release();
				p = nullptr;
			});
		}
		return m_textures[{texturePath, dds}];
	}


	void TextureManager::update(double delta)
	{
		for (auto i : m_textures)
		{
			if (i.second.getReferenceCount() == 1)
			{
				i.second.deletePtr();
			}
		}
	}

}