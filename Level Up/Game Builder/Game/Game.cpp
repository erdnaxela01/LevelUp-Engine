
#include "Game.h"
#include "../../Developer/Core/StandardTemplates.h"
#include "../Prebuilt Objects/MovementLevelObject.h"
#include "../../Developer/Services/ServiceLocator.h"
#include "../../Developer/Engine/MVC/MVC.h"
using namespace DirectX;

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
        mlo->setPosition(200.0f, 200.0f);
		return result;
	}
}