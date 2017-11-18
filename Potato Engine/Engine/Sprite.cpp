#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}


void Sprite::render()
{
	if (m_hasClipRect)
	{
		renderMain(&m_clipRect);
	}
	else
	{
		renderMain();
	}
	
}


void Sprite::setClipRect(SDL_Rect rect)
{
	m_clipRect = rect;
	m_hasClipRect = true;
}


SDL_Rect Sprite::getClipRect()
{
	return m_clipRect;
}


void Sprite::resetClipRect()
{
	m_hasClipRect = false;
}
