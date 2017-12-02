#include "gameConfig.h"

#include "Engine.h"
#include "SceneManager.h"
#include "PrefabsFactory.h"


const int SCREEN_SIZE = 2;
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 224 + 32 / SCREEN_SIZE;


std::vector<std::string> renderLayersConfig()
{
	return std::vector<std::string>{"Background", "Main", "Foreground" };
}


bool scenesConfig()
{
	// Success flag
	bool success = true;

	// Usage: import and add every Scene as shown in the following line (where SomeScene is a class that inherits from Scene):
	//success &= engine->sceneManager->addScene<SomeScene>();
	if (success)
	{
		engine->sceneManager->loadScene(0);
	}
	return success;
}


bool prefabsConfig()
{
	// Success flag
	bool success = true;

	// Usage: import adn add every Prefab as shown on the following line (where somePrefab is a class that inherits from Prefab):
	// success &= engine->prefabsFactory->addPrefab<SomePrefab>("SomePrefab");
	// Note that the parameter in the addPrefab method can be any string, but it should be unique. This string will be used to retrieve the Prefab later on.

	return success;
}