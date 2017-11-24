#ifndef H_INPUT_CONTROLLER
#define H_INPUT_CONTROLLER

#include <map>
#include "SDL2/include/SDL_stdinc.h"
#include "SDL2/include/SDL_scancode.h"


class InputController final
{
public:
	InputController();
	~InputController();

	bool getKey(SDL_Scancode scancode);
	bool getKeyUp(SDL_Scancode scancode);
	bool getKeyDown(SDL_Scancode scancode);

	void clearStates();
	void setKeyUp(SDL_Scancode scancode);
	void setKeyDown(SDL_Scancode scancode);

private:
	enum class KeyState {
		UP,
		DOWN
	};

	const Uint8* currentKeyStates;
	std::map<SDL_Scancode, KeyState> keyUpDownStates;
};


#endif // !H_INPUT_CONTROLLER
