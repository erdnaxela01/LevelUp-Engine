#ifndef __MOVEMENTLEVELOBJECT_H
#define __MOVEMENTLEVELOBJECT_h

#include "../../Developer/Engine/BasicLevelObject/BaseMVCObject.h"
#include <string>
namespace LevelUp
{
    //pre built object that can be created for rapid prototyping
    //Alex Sabourin April 2015
	class MovementLevelObject : public BaseMVCObject
    {
    public:
        MovementLevelObject(std::wstring fname, float speed = 300.0f, float spinSpeed = 5.0f);
        virtual ~MovementLevelObject();
    };
}

#endif