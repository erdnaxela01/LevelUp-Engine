#include "DirectXMatrixContainer.h"
#include  <DirectXMath.h>

namespace LevelUp
{
    DirectXMatrixContainer::DirectXMatrixContainer(DirectX::XMMATRIX* m)
    {
        m_matrix = m;
    }
    DirectXMatrixContainer::~DirectXMatrixContainer()
    {
        m_matrix = nullptr;
    }
    void DirectXMatrixContainer::setFloatAt(int r, int c, LVLfloat f)
    {
        DirectX::XMFLOAT4X4 m2;
        DirectX::XMStoreFloat4x4(&m2, *m_matrix);

        switch (r)
        {
        case 0:
            switch (c)
            {
            case 0:
                m2._11 = f.x;
                break;
            case 1:
                m2._12 = f.x;
                break;
            case 2:
                m2._13 = f.x;
                break;
            case 3:
                m2._14 = f.x;
                break;
            }
            break;
        case 1:
            switch (c)
            {
            case 0:
                m2._21 = f.x;
                break;
            case 1:
                m2._22 = f.x;
                break;
            case 2:
                m2._23 = f.x;
                break;
            case 3:
                m2._24 = f.x;
                break;
            }
            break;
        case 2:
            switch (c)
            {
            case 0:
                m2._31 = f.x;
                break;
            case 1:
                m2._32 = f.x;
                break;
            case 2:
                m2._33 = f.x;
                break;
            case 3:
                m2._34 = f.x;
                break;
            }
            break;
        case 3:
            switch (c)
            {
            case 0:
                m2._41 = f.x;
                break;
            case 1:
                m2._42 = f.x;
                break;
            case 2:
                m2._43 = f.x;
                break;
            case 3:
                m2._44 = f.x;
                break;
            }
            break;
        }
        *m_matrix = DirectX::XMLoadFloat4x4(&m2);
    }
    LVLfloat DirectXMatrixContainer::getFloatAt(int r, int c)
    {
        DirectX::XMFLOAT4X4 m2;
        DirectX::XMStoreFloat4x4(&m2, *m_matrix);

        switch (r)
        {
        case 0:
            switch (c)
            {
            case 0:
                return m2._11;
                break;
            case 1:
                return m2._12;
                break;
            case 2:
                return m2._13;
                break;
            case 3:
                return m2._14;
                break;
            }
            break;
        case 1:
            switch (c)
            {
            case 0:
                return m2._21;
                break;
            case 1:
                return m2._22;
                break;
            case 2:
                return m2._23;
                break;
            case 3:
                return m2._24;
                break;
            }
            break;
        case 2:
            switch (c)
            {
            case 0:
                return m2._31;
                break;
            case 1:
                return m2._32;
                break;
            case 2:
                return m2._33;
                break;
            case 3:
                return m2._34;
                break;
            }
            break;
        case 3:
            switch (c)
            {
            case 0:
                return m2._41;
                break;
            case 1:
                return m2._42;
                break;
            case 2:
                return m2._43;
                break;
            case 3:
                return m2._44;
                break;
            }
            break;
        }
    }
}