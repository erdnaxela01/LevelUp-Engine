#include "Game.h"
#include "../../Developer/Core/StandardTemplates.h"
#include "../Prebuilt Objects/MovementLevelObject.h"
#include "../../Developer/Services/ServiceLocator.h"
#include "../../Developer/Engine/MVC/MVC.h"
#include "../Prebuilt Objects/ECS/ParticleComponent.h"
#include "../../Developer/Graphics/Color.h"

namespace LevelUp
{
	Game::Game() : Scene("Game")
	{
	}


	Game::~Game()
	{
        SafeDelete(mlo);
	}

	void Game::update(double delta)
	{
        //if created with MVC you dont need to update or render your objects, thats taken care of
	}

	void Game::render()
	{
        //focus more on making a game
        //go go go!
	}

	bool Game::loadContent()
	{
		bool result = true;

        mlo = new MovementLevelObject(L"Ship.png");
        mlo->getView()->setZ(0.5f);
        ParticleComponent* p = new ParticleComponent(200, Color::getForestGreen());
        p->trackObject(mlo);
        p->activate(1.0, 0.001, 30.0f, 90.0f, 200.0f, 300.0f);
        mlo->addComponent(p);
        
        mlo->setPosition(200.0f, 200.0f);
		return result;
	}
}