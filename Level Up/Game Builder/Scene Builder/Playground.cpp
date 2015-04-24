#include "Playground.h"
#include "../Game/Game.h"
#include "../../Developer/Engine/SceneManager/SceneManagerHeaders.h"
#include "../../Developer/Engine/TheEngine.h"
#include "../Prebuilt Objects/ECS/ParticleSystem.h"

namespace LevelUp
{
    void Playground::SystemAdd()
    {
        TheEngine::getInstance()->getSystems()->addSystem(new ParticleSystem);
    }

    void Playground::SceneLayout()
    {
        //set up your scenes here and start them
        TheEngine::getInstance()->getSceneManager()->addSceneToMap(new Game);
        TheEngine::getInstance()->getSceneManager()->pushScene("Game");








    }
}