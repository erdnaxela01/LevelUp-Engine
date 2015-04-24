#include "DirectXViewport.h"
#include "../Services/ServiceLocator.h"

namespace LevelUp
{
    DirectXViewport::DirectXViewport()
    {
        //create the directX viewport with all the intial values
        SecureZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));
        m_viewport.TopLeftX = 0.0f;
        m_viewport.TopLeftY = 0.0f;
        //viewport is set to be the size of the screen
        m_viewport.Width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
        m_viewport.Height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
        m_viewport.MinDepth = 0.0f;
        m_viewport.MaxDepth = 1.0f;
    }

    void  DirectXViewport::setWidth(float w)
    {
        m_viewport.Width = w;
    }
    void  DirectXViewport::setHeight(float h)
    {
        m_viewport.Height = h;
    }
    void  DirectXViewport::setTopX(float x)
    {
        m_viewport.TopLeftX = x;
    }
    void  DirectXViewport::setTopY(float y)
    {
        m_viewport.TopLeftY = y;
    }

    float  DirectXViewport::getWidth()
    {
        return m_viewport.Width;
    }
    float  DirectXViewport::getHeight()
    {
        return m_viewport.Height;
    }
    float  DirectXViewport::getX()
    {
        return m_viewport.TopLeftX;
    }
    float  DirectXViewport::getY()
    {
        return m_viewport.TopLeftY;
    }

    void  DirectXViewport::setViewPort()
    {
        //sets the view port
        ServiceLocator::getRenderService()->getContext()->RSSetViewports(1, &m_viewport);
    }
}