#include "RenderersManager.h"

#include "../SDL2_image/include/SDL_image.h"
#include "globals.h"
#include "ComponentType.h"
#include "gameConfig.h"
#include "Renderer.h"
#include "GameObject.h"


RenderersManager::RenderersManager()
	: m_window(nullptr)
	, m_renderer(nullptr)
	, m_fontSize(28)
{
}


RenderersManager::~RenderersManager()
{
}


SDL_Renderer * RenderersManager::getRenderer()
{
	return m_renderer;
}


ComponentType RenderersManager::managedComponentType()
{
	return ComponentType::Renderer;
}


void RenderersManager::update()
{
	// Note: refreshComponents ensures that all Reference in m_components are valid, so they can be safely used
	refreshComponents();

	// Set Render Color to white
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0xFF);

	// Clear screen
	SDL_RenderClear(m_renderer);

	for (Reference<Component>& componentRef : m_components)
	{
		Renderer* renderer = static_cast<Renderer*>(componentRef.get());
		// Actual update
		if (renderer->isActive())
		{
			renderer->render();
		}

	}

	// Update screen
	SDL_RenderPresent(m_renderer);
}


bool RenderersManager::init()
{
	// Success flag
	bool success = true;

	// Create window
	m_window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE, SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		OutputLog("Error: Window could not be created! SDL Error: %s", SDL_GetError());
		success = false;
	}
	else
	{
		// Create Renderer for window (used for texture rendering)
		Uint32 flags = SDL_RENDERER_ACCELERATED;
		m_renderer = SDL_CreateRenderer(m_window, -1, flags);
		if (m_renderer == nullptr)
		{
			OutputLog("Error: Renderer could not be created! SDL Error: %s", SDL_GetError());
			success = false;
		}
	}

	return success;
}


void RenderersManager::close()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
}


bool RenderersManager::initializeComponent(Reference<Component> component)
{
	// At this point, we know that component is a Renderer (or a sub-class there-of)
	if (component)
	{
		auto renderer = component.static_reference_cast<Renderer>();
		renderer->m_renderer = m_renderer;

		return true;
	}
	return false;
}
