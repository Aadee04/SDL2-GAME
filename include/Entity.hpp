#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	void setPos(float x, float y);
	void setScale(float w, float h);
	void setAngle(float angle);

	Vector2f& getPos();
	float getAngle();
	Vector2f getScale();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

private:
	Vector2f pos;
	float angle = 0;
	Vector2f scale = Vector2f(1, 1);
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};