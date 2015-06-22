#include "Playground.h"
#include "../Game/Game.h"
#include "../../Developer/Engine/SceneManager/SceneManagerHeaders.h"
#include "../../Developer/Engine/TheEngine.h"
#include "../Prebuilt Objects/ECS/ParticleSystem.h"

namespace LevelUp
{
    void Playground::SystemAdd()
    {
        getEngine()->getSystems()->addSystem(new ParticleSystem());
    }

    void Playground::SceneLayout()
    {
        //set up your scenes here and start them
        getEngine()->getSceneManager()->addSceneToMap(new Game);
        getEngine()->getSceneManager()->pushScene("Game");








    }
}