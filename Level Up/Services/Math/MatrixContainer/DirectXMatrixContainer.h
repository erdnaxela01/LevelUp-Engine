#ifndef __DIRECTXMATRIXCONTAINER_H
#define __DIRECTXMATRIXCONTAINER_H

#include "MatrixContainer.h"
#include <DirectXMath.h>

namespace LevelUp
{
    class DirectXMatrixContainer :public MatrixContainer
    {
    public:
        DirectXMatrixContainer(DirectX::XMMATRIX* m);
        virtual ~DirectXMatrixContainer();
        void setFloatAt(int r, int c, LVLfloat f);
        LVLfloat getFloatAt(int r, int c);
    private:
        DirectX::XMMATRIX* m_matrix;
    };
}


#endif