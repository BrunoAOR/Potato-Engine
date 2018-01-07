#include "gameConfig.h"

#include "Engine.h"
#include "SceneManager.h"
#include "PrefabsFactory.h"
#include "CollisionSystemSetup.h"


const std::string GAME_NAME = "Potato Engine Game";
const bool USE_VSYNC = false;
const int SCREEN_SIZE = 2;
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 224;


bool scenesConfig()
{
	// Success flag
	bool success = true;

	// Usage: import and add every Scene as shown in the following line (where SomeScene is a class that inherits from Scene)
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

	// Usage: import and add every Prefab as shown on the following line (where somePrefab is a class that inherits from Prefab)
	//success &= engine->prefabsFactory->addPrefab<SomePrefab>("SomePrefab");
	// Note that the parameter in the addPrefab method can be any string, but it should be unique. This string will be used to retrieve the Prefab later on.

	return success;
}


std::vector<std::string> renderLayersConfig()
{
	return std::vector<std::string>{ "Background", "Main", "Foreground" };
}


CollisionSystemSetup collisionSystemSetup()
{
	CollisionSystemSetup css;
	// The list of collisionLayers. There is always a "default" layer that collides with everything else
	css.layersNames = std::vector<std::string>{ "Player", "Scenario", "Enemy" };
	// The matrix that describes whether a collider from a certain layer collides with one from another (or the same) layer
	css.collisionMatrix.push_back(std::vector<bool>{ false, true, true });
	css.collisionMatrix.push_back(std::vector<bool>{  true, false, false });
	css.collisionMatrix.push_back(std::vector<bool>{  true, false, false });
	// Whether the zIndexCollisionRange is taken into account when calculating collisions within a layer (if not, collisions are calculated regardless of the zIndex)
	css.useZIndexWithinLayer = true;
	// Whether the zIndexCollisionRange is taken into account when calculating collisions among different colliding layers (if not, collisions are calculated regardless of the zIndex)
	css.useZIndexAmongLayers = true;
	// The zIndex difference range within which a pair of colliders are considered as candidates for collision
	css.zIndexCollisionRange = 0;
	return css;
}
