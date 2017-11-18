#include "ComponentsManager.h"

#include "ComponentManager.h"
#include "BehavioursManager.h"
#include "CollidersManager.h"
#include "RenderersManager.h"


ComponentsManager::ComponentsManager()
{
}


ComponentsManager::~ComponentsManager()
{
}


bool ComponentsManager::sendToManager(Reference<Component> component)
{
	for (auto compManager : componentManagers)
	{
		if (compManager->subscribeComponent(component))
		{
			return true;
		}
	}
	return false;
}


bool ComponentsManager::init()
{
	// Success flag
	bool success = true;

	componentManagers.push_back(new BehavioursManager());
	componentManagers.push_back(new CollidersManager());
	componentManagers.push_back(new RenderersManager());
	for (auto compManager : componentManagers)
	{
		success &= compManager->init();
	}
	return success;
}


void ComponentsManager::close()
{
	for (auto compManager : componentManagers)
	{
		compManager->close();
		delete compManager;
	}
	componentManagers.clear();
}


void ComponentsManager::update()
{
	for (auto compManager : componentManagers)
	{
		compManager->update();
	}
}
