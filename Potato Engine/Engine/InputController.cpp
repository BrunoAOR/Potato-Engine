#include "InputController.h"

#include "SDL2/include/SDL_keyboard.h"


InputController::InputController()
{
	currentKeyStates = SDL_GetKeyboardState(NULL);
}


InputController::~InputController()
{
	currentKeyStates = nullptr;
}


bool InputController::getKey(SDL_Scancode scancode)
{
	return currentKeyStates[scancode];
}


bool InputController::getKeyUp(SDL_Scancode scancode)
{
	if (keyUpDownStates.count(scancode))
	{
		return keyUpDownStates[scancode] == KeyState::UP;
	}
	return false;
}


bool InputController::getKeyDown(SDL_Scancode scancode)
{
	if (keyUpDownStates.count(scancode))
	{
		return keyUpDownStates[scancode] == KeyState::DOWN;
	}
	return false;
}


void InputController::clearStates()
{
	keyUpDownStates.clear();
}


void InputController::setKeyUp(SDL_Scancode scancode)
{
	keyUpDownStates[scancode] = KeyState::UP;
}


void InputController::setKeyDown(SDL_Scancode scancode)
{
	keyUpDownStates[scancode] = KeyState::DOWN;
}
