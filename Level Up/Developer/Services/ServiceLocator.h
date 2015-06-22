#ifndef __SERVICELOCATOR_H
#define __SERVICELOCATOR_H

#include "Renderer.h"
#include "ScreenSize.h"
#include "Math\MathAdapters\MathAdapter.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
    //as services are provided the service locator will give you access to specific services
    //Alex Sabourin April 2015
	class ServiceLocator
	{
	public:
		ServiceLocator();
		virtual ~ServiceLocator();

        //provide a render service
		static void provideRenderService(APT::WeakPointer<Renderer> render);
        //get a render service
		static APT::WeakPointer<Renderer> getRenderService();

        //provide a screen size service
		static void provideScreenSizeService(APT::WeakPointer<ScreenSize> size);
        //get a screen size service
		static APT::WeakPointer<ScreenSize> getScreenSizeService();

        //provide a math adapter 
		static void provideMathAdapter(APT::WeakPointer<MathAdapter> ada);
        //get a math adapter
		static APT::WeakPointer<MathAdapter> getMathAdapter();

	private:
		//all services
		static APT::WeakPointer<Renderer> m_renderService;
		static APT::WeakPointer<ScreenSize> m_screenSizeService;
		static APT::WeakPointer<MathAdapter> m_mathAdapter;
	};
}


#endif