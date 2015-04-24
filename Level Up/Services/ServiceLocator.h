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

        //provide a render service
		static void provideRenderService(Renderer* render);
        //get a render service
		static Renderer* getRenderService();

        //provide a screen size service
		static void provideScreenSizeService(ScreenSize* size);
        //get a screen size service
		static ScreenSize* getScreenSizeService();

        //provide a math adapter 
        static void provideMathAdapter(MathAdapter* ada);
        //get a math adapter
        static MathAdapter* getMathAdapter();

	private:
		//all services
		static Renderer* m_renderService;
		static ScreenSize* m_screenSizeService;
        static MathAdapter* m_mathAdapter;
	};
}


#endif