#ifndef __MOVEMENTLEVELOBJECT_H
#define __MOVEMENTLEVELOBJECT_h

#include "../../Developer/Engine/BasicLevelObject/BaseLevelObject.h"
#include <string>
namespace LevelUp
{
    //pre built object that can be created for rapid prototyping
    //Alex Sabourin April 2015
    class MovementLevelObject : public BaseLevelObject
    {
    public:
        MovementLevelObject(std::wstring fname, float speed = 300.0f, float spinSpeed = 5.0f);
        virtual ~MovementLevelObject();
    };
}

#endif