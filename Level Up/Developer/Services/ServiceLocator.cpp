#include "ServiceLocator.h"
#include <assert.h>

namespace LevelUp
{

	Renderer* ServiceLocator::m_renderService = nullptr;
	ScreenSize* ServiceLocator::m_screenSizeService = nullptr;
    MathAdapter* ServiceLocator::m_mathAdapter = nullptr;

	ServiceLocator::ServiceLocator()
	{

	}
	ServiceLocator::~ServiceLocator()
	{

	}

	void ServiceLocator::provideRenderService(Renderer* render)
	{
        assert(render != nullptr);
		m_renderService = render;
	}
	Renderer* ServiceLocator::getRenderService()
	{
        assert(m_renderService != nullptr);
		return m_renderService;
	}

	void  ServiceLocator::provideScreenSizeService(ScreenSize* size)
	{
        assert(size != nullptr);
		m_screenSizeService = size;
	}
	ScreenSize*  ServiceLocator::getScreenSizeService()
	{
        assert(m_screenSizeService != nullptr);
		return m_screenSizeService;
	}

    void ServiceLocator::provideMathAdapter(MathAdapter* ada)
    {
        assert(ada != nullptr);
        m_mathAdapter = ada;
    }
    MathAdapter* ServiceLocator::getMathAdapter()
    {
        assert(m_mathAdapter != nullptr);
        return m_mathAdapter;
    }
}
