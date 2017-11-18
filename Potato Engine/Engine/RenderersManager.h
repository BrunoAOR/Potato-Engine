#ifndef H_RENDERERS_MANAGER
#define H_RENDERERS_MANAGER

#include "../SDL2/include/SDL.h"
#include "ComponentManager.h"
#include "Reference.h"

class Component;


class RenderersManager final :
	public ComponentManager
{
	friend class ComponentsManager;
public:
	~RenderersManager();

private:
	RenderersManager();

	SDL_Renderer * getRenderer();

	// Inherited via ComponentManager
	virtual ComponentType managedComponentType() override;
	virtual void update() override;
	virtual bool init() override;
	virtual void close() override;
	virtual bool initializeComponent(Reference<Component> component) override;

	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	int m_fontSize;
};


#endif // !H_RENDERERS_MANAGER