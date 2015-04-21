#ifndef __SERVICELOCATOR_H
#define __SERVICELOCATOR_H

#include "Renderer.h"
#include "ScreenSize.h"
#include "Math\MathAdapters\MathAdapter.h"

namespace LevelUp
{
    //as services are provided the service locator will give you access to specific services
    //Alex Sabourin April 2015
	class ServiceLocator
	{
	public:
		ServiceLocator();
		~ServiceLocator();

		static void provideRenderService(Renderer* render);
		static Renderer* getRenderService();

		static void provideScreenSizeService(ScreenSize* size);
		static ScreenSize* getScreenSizeService();

        static void provideMathAdapter(MathAdapter* ada);
        static MathAdapter* getMathAdapter();

	private:
		//all services
		static Renderer* m_renderService;
		static ScreenSize* m_screenSizeService;
        static MathAdapter* m_mathAdapter;
	};
}


#endif