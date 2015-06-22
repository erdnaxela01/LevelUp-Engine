#ifndef __DIRECTXMATRIXCONTAINER_H
#define __DIRECTXMATRIXCONTAINER_H

#include "MatrixContainer.h"
#include <DirectXMath.h>
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"
namespace LevelUp
{
    /*
    inherited from the matrix container the direct x matrix container is used to change it to a lvl matrix or to convert a lvl matrix to it\
    -Alex Sabourin
    */
    class DirectXMatrixContainer :public MatrixContainer
    {
    public:

        DirectXMatrixContainer(APT::WeakPointer<DirectX::XMMATRIX> m);
        virtual ~DirectXMatrixContainer();
        void setFloatAt(int r, int c, LVLfloat f);
        LVLfloat getFloatAt(int r, int c);
    private:
		APT::WeakPointer<DirectX::XMMATRIX> m_matrix;
    };
}


#endif