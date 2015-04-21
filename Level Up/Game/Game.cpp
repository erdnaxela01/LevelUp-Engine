
#include "Game.h"
#include "../Graphics/Sprite.h"
#include "../Core/StandardTemplates.h"
#include "../Services/WindowScreen.h"
#include "../Engine/MVC/MVC.h"
#include "../UI/Cameras/Camera.h"
#include "../Graphics/Rectangle.h"
#include "../Engine/BasicLevelObject/BaseLevelObject.h"
#include "../UI/Cameras/Special Cameras/TrackingCamera.h"
#include "../Engine/SceneManager/Scene.h"
#include "../Services/ServiceLocator.h"
#include "../Engine/Helper/Helpers.h"
#include "../Services/Math/LevelUpMath.h"
#include "../Services/Math/MathAdapters/MathAdapter.h"
#include "../Prebuilt Objects/MovementLevelObject.h"

using namespace DirectX;

namespace LevelUp
{
	Game::Game() : Scene("Game")
	{
	}


	Game::~Game()
	{
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
		return result;
	}
}