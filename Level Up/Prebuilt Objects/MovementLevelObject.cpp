#include "MovementLevelObject.h"
#include "../Engine/MVC/MovementModel.h"
#include "../Engine/MVC/MovementKeyController.h"
#include "../Engine/MVC/MovementSpriteView.h"

namespace LevelUp
{
    MovementLevelObject::MovementLevelObject(std::wstring fname, float speed, float spinSpeed)
    {
        MovementModel* m = new MovementModel(speed, spinSpeed);
        MovementSpriteView* v = new MovementSpriteView(fname, m, 1.0f);
        MovementKeyController* c = new MovementKeyController(m);

        initialize(m, v, c);
    }
    MovementLevelObject::~MovementLevelObject()
    {

    }
}