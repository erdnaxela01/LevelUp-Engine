#ifndef __GAME_H
#define __GAME_H

#include "../Engine/SceneManager/Scene.h"
#include <string>

namespace LevelUp
{
	class TrackingCamera;
	class MovementLevelObject;
	class Game : public Scene
	{
	public:
		Game();
		~Game();
		void update(double delta);
		void render();
		bool loadContent();
		bool unloadContent() { return true; };
	private:
        MovementLevelObject *mlo;
		
	};
}
#endif
