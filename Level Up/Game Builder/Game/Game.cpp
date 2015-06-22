#include "Game.h"
#include "../../Developer/Core/StandardTemplates.h"
#include "../Prebuilt Objects/MVC/MovementLevelObject.h"
#include "../../Developer/Services/ServiceLocator.h"
#include "../../Developer/Engine/MVC/MVC.h"
#include "../Prebuilt Objects/ECS/ParticleComponent.h"
#include "../../Developer/Graphics/Color.h"
#include "../../Developer/Graphics/Circle.h"
#include "../../Developer/Graphics/ViewShape.h"
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
#include "../../Developer/Pipeline/TReceiver.h"
#include "../../Developer/Pipeline/TSender.h"
#include "../../Developer/Pipeline/OmniSender.h"
#include "../../Developer/Logging/Logger.h"

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
		box1.push_back((CollisionAttribute*)(mlo->getAttributesOfType("CollisionAttribute")[0].getPtr()));
		std::vector<CollisionAttribute*> box2;
		box2.push_back((CollisionAttribute*)(mlo2->getAttributesOfType("CollisionAttribute")[0].getPtr()));


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

		c->setX(mlo->getPosition().x);
		c->setY(mlo->getPosition().y);
	}

	void Game::render()
	{
        //focus more on making a game
        //go go go!
		
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

		//ServiceLocator::getRenderService()->setBgColor(Color::getGold());

		mlo2 = new MovementLevelObject(L"Ship.png");
		mlo2->getController()->stopControl();
        ParticleComponent* p = new ParticleComponent(200, Color::getForestGreen());
		p->setMultipleColors({ Color::getAqua(), Color::getDeepPink(), Color::getMagenta(), Color::getChocolate(), Color::getGreen() });
        p->trackObject(mlo);
        p->activate(1.0, 0.003, 0.0f, 360.0f, 200.0f);
        mlo->addComponent(p);
		p->setCanFade(true);
		mlo->addAttribute(new CollisionAttribute(mlo->getView()->getW(), mlo->getView()->getH()));
		mlo2->addAttribute(new CollisionAttribute(mlo2->getView()->getW(), mlo2->getView()->getH()));
		t = new TrackingCamera(mlo);
		t->setIsTracking(true);
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

		c = new ViewShape (new Circle(LVLfloat4(1.0f, 0.0f, 1.0f, 1.0f), 100.0f));
		c->getShape()->setAlpha(0.5f);
		c->setZ(10.0f);

		TReceiver<int> r;
		TSender<int> s;
		r.slot(&s);
		s.send(5);
		for (int i = 0; i < 100; i++)
		{
			s.send(i);
		}
		TSender<int> s2;
		r.slot(&s2);

		s2.send(10);

		s2.getBack();
		r.back();
		r.front();
		s.getFront();

		TReceiver<int> r1;
		TReceiver<int> r2;

		OmniSender<int> s3;
		r1.slot(&s3);
		r2.slot(&s3);

		s3.send(5000);

		return result;
	}
}