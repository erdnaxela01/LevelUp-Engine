#ifndef __GAME_BASE_H
#define __GAME_BASE_H
#include "Dx11Base.h"
#include "../Services/Renderer.h"
#include "../Services/Math/DataTypes.h"
#include "DirectXViewport.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <d3d11.h>
class Game;

namespace LevelUp
{
    /*
    The render engine, this does the grunt of the work when it comes to rendering and is the core of direct x
    -Alex Sabourin April 2015
    */
	class RenderEngine final :
		public Dx11Base, public Renderer
	{
	public:
        //load all the necessary content 
		virtual bool loadContent();
        //ubnload all the content
		virtual void unloadContent();

        //tells the render that i can start rendering
		virtual void beginRender();
		//display on screen
        void finishRender();

        //get the device
		ID3D11Device* getDevice();
        //get the context
		ID3D11DeviceContext* getContext();
        //get matrices
        LVL4X4matrix getVPMatrix();
        //set the view point matrix
        void setVPMatrix(const LVL4X4matrix &vp);
        //shutdown render engine - MUST be shutdown
		void shutdown();

        //compil the shaders
		bool CompileD3DShader(std::wstring filePath, std::string entry, std::string shaderModel, ID3DBlob** buffer);

        //factory function to create a view port
        DirectXViewport* produceViewport();

		//set the screen to full screen
		void setFullScreenMode(bool b);
		//resize buffer
		void resizeBuffer(LVLfloat2 size);

        //constructor and destructor
		RenderEngine();
		~RenderEngine() {};

	private:
        //the color map map sampler
		ID3D11SamplerState* m_colorMapSampler;
        //the state of the alpha blend
		ID3D11BlendState* m_alphaBlendState;
        //the view point matrix
        LVL4X4matrix m_vpMatrix;

	};
}
#endif

