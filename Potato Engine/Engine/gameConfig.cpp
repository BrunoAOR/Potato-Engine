#include "gameConfig.h"

#include "Engine.h"
#include "SceneManager.h"


const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 224;
const int SCREEN_SIZE = 1;

bool scenesConfig()
{
	// Success flag
	bool success = true;

	// Usage: import and add everyScene as shown in the following line (where SomeScene is a class that inherits from Scene):
	//success &= engine->sceneManager->addScene<SomeScene>();

	engine->sceneManager->loadScene(0);
	return success;
}
