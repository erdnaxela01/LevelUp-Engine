#include "Game.h"
#include "../../Developer/Core/StandardTemplates.h"
#include "../Prebuilt Objects/MVC/MovementLevelObject.h"
#include "../../Developer/Services/ServiceLocator.h"
#include "../../Developer/Engine/MVC/MVC.h"
#include "../Prebuilt Objects/ECS/ParticleComponent.h"
#include "../../Developer/Graphics/Color.h"
#include "../../Developer/Graphics/Circle.h"
#include "../../Developer/UI/Cameras/Special Cameras/TrackingCamera.h"
#include "../../Developer/Engine/TheEngine.h"
#include "../Prebuilt Objects/Attributes/CollisionAttribute.h"
#include "../../Developer/Graphics/Rectangle.h"
#include "../../Developer/Audio/AudioHeaders.h"
#include "../Prebuilt Objects/MVC/MovementSpriteView.h"
#include "../../Developer/File Streams/FileStreams.h"
#include "../../Developer/Graphics/Sprite.h"
#include "../../Developer/Engine/BasicLevelObject/GameObject.h"
#include "../../Developer/Engine/Command/CameraResizeCommand.h"


namespace LevelUp
{
	Game::Game() : Scene("Game")
	{
	}


	Game::~Game()
	{
		if (mlo != nullptr)
		{
			delete mlo;
			mlo = nullptr;
		}
		if (mlo2 != nullptr)
		{
			delete mlo2;
			mlo2 = nullptr;
		}
		if (t != nullptr)
		{
			delete t;
			t = nullptr;
		}
		if (mus != nullptr)
		{
			delete mus;
			mus = nullptr;
		}
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
		if (getEngine()->justPressed(LevelUpKeys::KEY_SPACE))
		{
			mlo->getView()->setZ(mlo->getView()->getZ() * -1);
		}
	}

	void Game::render()
	{
        //focus more on making a game
        //go go go!

		Circle c(LVLfloat4(1.0f, 0.0f, 1.0f, 1.0f), 100.0f);
		c.setPosition(mlo->getPosition().x, mlo->getPosition().y);
		c.setAlpha(0.5f);
		c.render();
		
	}

	bool Game::loadContent()
	{
		bool result = true;
		getInitialCamera()->setZoom(0.2f);
		mus = new SoundEffect("Eagle_Call.wav");
		mus->play();
        mlo = new MovementLevelObject(L"Ship.png");
		mlo->setPosition(200.0f, 200.0f);
        mlo->getView()->setZ(1.5f);

		mlo2 = new MovementLevelObject(L"HatShip.png");
		mlo2->getController()->stopControl();
        ParticleComponent* p = new ParticleComponent(200, Color::getForestGreen());
		p->setMultipleColors({ Color::getAqua(), Color::getDeepPink(), Color::getMagenta(), Color::getChocolate(), Color::getForestGreen() });
        p->trackObject(mlo);
        p->activate(1.0, 0.001);
        mlo->addComponent(p);
		p->setCanFade(true);
		mlo->addAttribute(new CollisionAttribute(mlo->getView()->getW(), mlo->getView()->getH()));
		mlo2->addAttribute(new CollisionAttribute(mlo2->getView()->getW(), mlo2->getView()->getH()));
		t = new TrackingCamera(mlo);
		t->setIsTracking(false);
		removeInitialCamera();
		//t->setZoom(2.0f);

		GameObject gam(L"Ship.png", 32, 32);

        
		mlo->setPosition(200.0f, 200.0f);


		TextFileStream stream("Tist.txt");
		std::vector<std::string> text;
		text = stream.getFileTo(5);
		text = stream.getFileFrom(5);
		text = stream.getFileFromTo(3, 6);
		text.push_back(stream.getLine(5));

		OTextFileStream ostream("Tuxt.txt");
		ostream.writeToFile("11 \n");
		return result;
	}
}