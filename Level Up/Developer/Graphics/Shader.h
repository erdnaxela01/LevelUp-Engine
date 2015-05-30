#ifndef __SHADER_H
#define __SHADER_H

namespace LevelUp
{
	class Shader
	{
	public:
		Shader() {};
		virtual ~Shader() {};
		virtual void setActiveShader() = 0;
	private:
	};
}

#endif