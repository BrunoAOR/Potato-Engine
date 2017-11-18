#ifndef H_ENGINE
#define H_ENGINE

class TimeController;
class InputController;
class SceneManager;
class GameObjectsManager;
class ComponentsManager;


class Engine final
{
public:
	Engine();
	~Engine();

	bool init();
	void handleEvents(bool& shouldQuit);
	void loop();
	void close();

	TimeController* time = nullptr;
	InputController* input = nullptr;
	SceneManager* sceneManager = nullptr;
	GameObjectsManager* gameObjectsManager = nullptr;
	ComponentsManager* componentsManager = nullptr;

private:
	bool initSDL();
	bool initEngine();
};

extern Engine* engine;


#endif // !H_ENGINE
