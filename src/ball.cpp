#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Ball.hpp"
#include "Entity.hpp"
#include "Math.hpp"


Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex)
{
    // Sets initial movement speed and direction
    velocity.x = 5;
    direction = true;
}

void Ball::flip() // Flipping movement on collision
{
    velocity.x = -velocity.x;
    direction = !direction;
}

void Ball::Movement()
{
    // Changes the position by adding velocity coordinates
    this->setPos(this->getPos().x + velocity.x, this->getPos().y + velocity.y);
}

bool Ball::getDirection()
{
    return direction; // true = +ve direction, false = -ve direction
}
