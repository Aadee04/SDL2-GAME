#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Entity.hpp"
#include "Math.hpp"


class Ball : public Entity // Inheritance
{
    public:
        Ball(Vector2f p_pos, SDL_Texture* p_tex);
        void flip();
        void Movement();
        bool getDirection();
    private:
        Vector2f velocity;
        bool direction;
};