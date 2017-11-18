#ifndef H_SPRITE_RENDERER
#define H_SPRITE_RENDERER

#include "Renderer.h"


class SpriteRenderer :
	public Renderer
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	bool loadImage(std::string path);
	bool loadImage(std::string path, Uint32 colorKey);

	// Set color modulation
	void setColor(Uint8 r, Uint8 g, Uint8 b);

	// Set Blend Mode
	void setBlendMode(SDL_BlendMode blendMode);

	// Set alpha modulation
	void setAlpha(Uint8 a);

private:
	bool loadImage(std::string path, bool shouldColorKey, Uint32 colorKey);
};


#endif // !H_SPRITE_RENDERER
