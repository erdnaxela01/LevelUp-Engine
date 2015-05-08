#include "Game.h"
#include "../../Developer/Core/StandardTemplates.h"
#include "../Prebuilt Objects/MVC/MovementLevelObject.h"
#include "../../Developer/Services/ServiceLocator.h"
#include "../../Developer/Engine/MVC/MVC.h"
#include "../Prebuilt Objects/ECS/ParticleComponent.h"
#include "../../Developer/Graphics/Color.h"
#include "../../Developer/UI/Cameras/Special Cameras/TrackingCamera.h"
#include "../../Developer/Engine/TheEngine.h"
#include "../Prebuilt Objects/Attributes/CollisionAttribute.h"
#include "../../Developer/Graphics/Rectangle.h"
#include "../../Developer/Audio/AudioHeaders.h"

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
		std::vector<CollisionAttribute*> box1;
		box1.push_back((CollisionAttribute*)(mlo->getAttributesOfType("CollisionAttribute")[0]));
		std::vector<CollisionAttribute*> box2;
		box2.push_back((CollisionAttribute*)(mlo2->getAttributesOfType("CollisionAttribute")[0]));


		for (auto i : box1)
		{
			for (auto j : box2)
			{
				if (i->doesCollide(j->getCollisionRect()))
				{
				}
			}
		}
	}

	void Game::render()
	{
        //focus more on making a game
        //go go go!
		
	}

	bool Game::loadContent()
	{
		bool result = true;
		mus = new SoundEffect("Eagle_Call.wav");
		mus->play();
        mlo = new MovementLevelObject(L"Ship.png");
        mlo->getView()->setZ(1.5f);
		//mlo->getController()->stopControl();

		mlo2 = new MovementLevelObject(L"Ship.png");
		mlo2->getController()->stopControl();
        ParticleComponent* p = new ParticleComponent(200, Color::getForestGreen());
        p->trackObject(mlo);
        p->activate(1.0, 0.001);
        mlo->addComponent(p);
		p->setCanFade(true);
		mlo->addAttribute(new CollisionAttribute(mlo->getView()->getW(), mlo->getView()->getH()));
		mlo2->addAttribute(new CollisionAttribute(mlo2->getView()->getW(), mlo2->getView()->getH()));
		//t = new TrackingCamera(mlo);
		//removeInitialCamera();
        
		mlo->setPosition(200.0f, 200.0f);
		return result;
	}
}