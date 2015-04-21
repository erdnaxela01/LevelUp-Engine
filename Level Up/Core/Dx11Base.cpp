
#include "Dx11Base.h"
#include "../Services/ServiceLocator.h"
namespace LevelUp
{
	Dx11Base::Dx11Base() :m_driverType(D3D_DRIVER_TYPE_NULL),
		m_featureLevel(D3D_FEATURE_LEVEL_11_0),
		m_swapChain(0), m_backBufferTarget(0)
	{

		m_errorMessage = "";
	}


	Dx11Base::~Dx11Base()
	{
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
		m_hInstance = hInstance;
		m_hWnd = hWnd;


		unsigned int width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
		unsigned int height = ServiceLocator::getScreenSizeService()->getScreenSize().y;

		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
			D3D_DRIVER_TYPE_SOFTWARE
		};

		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0
		};

		unsigned int totalFeatureLevels = ARRAYSIZE(featureLevels);

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

		unsigned int creationFlags = 0;

#ifdef __DEBUG
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		HRESULT result;
		unsigned int driver = 0;

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
		if (FAILED(result))
		{
			m_errorMessage = "Failed to create the Direct3D device!";
			return false;
		}
		ID3D11Texture2D* backBufferTexture;
		result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
			(LPVOID*)&backBufferTexture);

		if (FAILED(result))
		{
			m_errorMessage = "Failed to get the swap cahin buffer!";
			return false;
		}

		result = m_d3dDevice->CreateRenderTargetView(backBufferTexture, 0,
			&m_backBufferTarget);

		if (backBufferTexture) backBufferTexture->Release();

		if (FAILED(result))
		{
			m_errorMessage = "Failed to create the render target view!";
			return false;
		}


		m_d3dContext->OMSetRenderTargets(1, &m_backBufferTarget, 0);


		return loadContent();

	}

}
