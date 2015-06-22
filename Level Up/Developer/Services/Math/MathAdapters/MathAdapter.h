#ifndef __MATHADAPTER_H
#define __MATHADAPTER_H

#include <DirectXMath.h>
#include "../MatrixContainer/MatrixContainer.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"
namespace LevelUp
{
    struct LVL4X4matrix;

    //Math adapter to contain ion the service locator
    //Alex Sabourin
    class MathAdapter
    {
    public:
        //tried to have it polymorphic without having to cast however the only way to have an adaptor that works will be to add these functions
        //and have them do nothing in the future. Thought of void pointers but thats a bad idea

        //FIXED IT

		MathAdapter() {};
		virtual ~MathAdapter() {};

        //convert to a speicfic matrix
		virtual void get4x4Matrix(LVL4X4matrix& m, APT::WeakPointer<MatrixContainer> con) = 0;
        //convert to a lvl matrix
		virtual void convertToLVLMatrix(APT::WeakPointer<LVL4X4matrix> mat, APT::WeakPointer<MatrixContainer> con) = 0;
    };
}


#endif