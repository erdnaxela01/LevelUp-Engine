#ifndef __BASE_H
#define __BASE_H
#include <string>

namespace LevelUp
{
    /*
    Is the basis of the Directx 11.1 rendering code, inherited by the render engine with startup and shutdown capabilites
    - Alex Sabourin April 2015
    */

	class Dx11Base
	{
	public:
		Dx11Base();
		virtual ~Dx11Base();

		//initialize direct x 11 devices, context, etc
		bool initialize(HINSTANCE hInstance, HWND hWnd);
        //shutdown all directx 11 content
		virtual void shutdown();

		//load all the content
		virtual bool loadContent();
        //unload all the content
		virtual void unloadContent();

	protected:
        //used for error checking the constructor
		std::string m_errorMessage;

        //handles to window specific things
		HINSTANCE m_hInstance;
		HWND m_hWnd;

        //specs of computer for direct x 11.1 to run on
		D3D_DRIVER_TYPE m_driverType;
		D3D_FEATURE_LEVEL m_featureLevel;

        //the kdirect x device
		ID3D11Device* m_d3dDevice;
        //the direct x context
		ID3D11DeviceContext* m_d3dContext;
        //the directx swapchain
		IDXGISwapChain* m_swapChain;
        //the secondary buffer
		ID3D11RenderTargetView* m_backBufferTarget;



	};
}

#endif