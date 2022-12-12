#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

Vector2f& Entity::getPos() // Returns the position Vector2f struct
{
	return pos;
}

SDL_Texture* Entity::getTex() // Returns the position SDL_Texture
{
	return tex;
}

float Entity::getAngle() // Returns the angle of the entity (required for SDL window rendering)
{
	return angle;
}

Vector2f Entity::getScale() // Returns the scale of the entity (required for SDL window rendering)
{
	return scale;
}

void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Entity::setAngle(float p_angle)
{
	angle = p_angle;
}

void Entity::setScale(float w, float h)
{
	scale.x = w;
	scale.y = h;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
