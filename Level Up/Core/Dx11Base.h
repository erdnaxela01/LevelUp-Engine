#ifndef __BASE_H
#define __BASE_H
#include <string>

using std::string;

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
		virtual void shutdown();

		//load and unload all the content
		virtual bool loadContent();
		virtual void unloadContent();

	protected:
		string m_errorMessage;


		HINSTANCE m_hInstance;
		HWND m_hWnd;


		D3D_DRIVER_TYPE m_driverType;
		D3D_FEATURE_LEVEL m_featureLevel;

		ID3D11Device* m_d3dDevice;
		ID3D11DeviceContext* m_d3dContext;
		IDXGISwapChain* m_swapChain;
		ID3D11RenderTargetView* m_backBufferTarget;



	};
}

#endif