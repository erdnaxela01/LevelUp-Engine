
#include "Dx11Base.h"
#include "../Services/ServiceLocator.h"
#include <objbase.h>
namespace LevelUp
{
    //set all the initial values of the direct x
	Dx11Base::Dx11Base() :m_driverType(D3D_DRIVER_TYPE_NULL),
		m_featureLevel(D3D_FEATURE_LEVEL_11_0),
		m_swapChain(0), m_backBufferTarget(0)
	{
		HRESULT result = CoInitialize(NULL);
		if (FAILED(result))
		{
			throw (std::runtime_error("could not co initialize"));
		}
		m_errorMessage = "";
	}


	Dx11Base::~Dx11Base()
	{

        //shut down all the stuff
		shutdown();
	}

	bool Dx11Base::loadContent()
	{
		//Override with demo specifics, if any...
		return true;
	}

	void Dx11Base::unloadContent()
	{
		//override with demo specifics, if any...
	}

	void Dx11Base::shutdown()
	{
        //unload all the content and release all the COMs
		unloadContent();

		if (m_backBufferTarget) m_backBufferTarget->Release();
		if (m_swapChain) m_swapChain->Release();
		if (m_d3dContext) m_d3dContext->Release();
		if (m_d3dDevice) m_d3dDevice->Release();
		m_d3dDevice = nullptr;
		m_d3dContext = nullptr;
		m_swapChain = nullptr;
		m_backBufferTarget = nullptr;
	}

	bool Dx11Base::initialize(HINSTANCE hInstance, HWND hWnd)
	{
        //initialize the base

        //pass in the windows values
		m_hInstance = hInstance;
		m_hWnd = hWnd;

        //get the width and the height of the screen
		unsigned int width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
		unsigned int height = ServiceLocator::getScreenSizeService()->getScreenSize().y;

        //determine all the driver types
		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
			D3D_DRIVER_TYPE_SOFTWARE
		};

        //get the number of all the driver types
		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

        //get all the feature levels of direct x
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0
		};

        //set the number of feature levels
		unsigned int totalFeatureLevels = ARRAYSIZE(featureLevels);

        //set up the swapchain description with all the initial values
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = height;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.Windowed = true;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // allows full screen mode switching

		unsigned int creationFlags = 0;

#ifdef __DEBUG
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

        //used for error checking
		HRESULT result;
		unsigned int driver = 0;

        //go through all the diver types and break if one of them works
		for (driver = 0; driver < totalDriverTypes; ++driver)
		{
			result = D3D11CreateDeviceAndSwapChain(0, driverTypes[driver], 0,
				creationFlags, featureLevels, totalFeatureLevels,
				D3D11_SDK_VERSION, &swapChainDesc, &m_swapChain,
				&m_d3dDevice, &m_featureLevel, &m_d3dContext);
			if (SUCCEEDED(result))
			{
				m_driverType = driverTypes[driver];
				break;
			}
		}
        //if none of them worked set the error message and return false
		if (FAILED(result))
		{
			m_errorMessage = "Failed to create the Direct3D device!";
			return false;
		}
        //set the texture of the swap chain
		ID3D11Texture2D* backBufferTexture;
		result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
			(LPVOID*)&backBufferTexture);

        //error checking
		if (FAILED(result))
		{
			m_errorMessage = "Failed to get the swap cahin buffer!";
			return false;
		}
        //create a render target with the backbuffer
		result = m_d3dDevice->CreateRenderTargetView(backBufferTexture, 0,
			&m_backBufferTarget);

        //release the texture
		if (backBufferTexture) backBufferTexture->Release();

        //error checking
		if (FAILED(result))
		{
			m_errorMessage = "Failed to create the render target view!";
			return false;
		}


        //set the output merger's render targets
		m_d3dContext->OMSetRenderTargets(1, &m_backBufferTarget, 0);


		return loadContent();

	}



}
