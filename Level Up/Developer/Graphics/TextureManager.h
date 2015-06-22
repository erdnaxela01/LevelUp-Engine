#ifndef __TEXTUREMANAGER_H
#define __TEXTUREMANAGER_H

#include <map>
#include <string>
#include <d3d11.h>
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"
#include "../Engine/MVC/Model.h"

namespace LevelUp
{
	class TextureManager : public Model
	{
	public:
		APT::ChangePointer<ID3D11ShaderResourceView> getTexture(std::wstring texturePath, bool dds);
		void releaseTexture(std::wstring texturePath, bool dds);
		void update(double delta);
	private:
		struct textureValues
		{
			std::wstring path;
			bool dds;

			bool operator< (const textureValues& t) const
			{
				return path < t.path;
			}
		};
		std::map<textureValues, APT::ChangePointer<ID3D11ShaderResourceView>> m_textures;
	};
}

#endif