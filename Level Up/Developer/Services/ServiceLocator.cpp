#include "ServiceLocator.h"
#include <assert.h>

namespace LevelUp
{

	APT::WeakPointer<Renderer> ServiceLocator::m_renderService = nullptr;
	APT::WeakPointer<ScreenSize> ServiceLocator::m_screenSizeService = nullptr;
	APT::WeakPointer<MathAdapter> ServiceLocator::m_mathAdapter = nullptr;

	ServiceLocator::ServiceLocator()
	{

	}
	ServiceLocator::~ServiceLocator()
	{

	}

	void ServiceLocator::provideRenderService(APT::WeakPointer<Renderer> render)
	{
        assert(render.getPtr() != nullptr);
		m_renderService = render;
	}
	APT::WeakPointer<Renderer> ServiceLocator::getRenderService()
	{
        assert(m_renderService.getPtr() != nullptr);
		return m_renderService;
	}

	void  ServiceLocator::provideScreenSizeService(APT::WeakPointer<ScreenSize> size)
	{
        assert(size.getPtr() != nullptr);
		m_screenSizeService = size;
	}
	APT::WeakPointer<ScreenSize>  ServiceLocator::getScreenSizeService()
	{
        assert(m_screenSizeService.getPtr() != nullptr);
		return m_screenSizeService;
	}

	void ServiceLocator::provideMathAdapter(APT::WeakPointer<MathAdapter> ada)
    {
        assert(ada.getPtr() != nullptr);
        m_mathAdapter = ada;
    }
	APT::WeakPointer<MathAdapter> ServiceLocator::getMathAdapter()
    {
        assert(m_mathAdapter.getPtr() != nullptr);
        return m_mathAdapter;
    }
}
