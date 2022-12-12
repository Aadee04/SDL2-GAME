#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"


class RenderWindow 
{
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
	    SDL_Texture* loadTexture(const char* p_filePath);
        void render(Entity& p_entity);
        void render(SDL_Texture* p_tex, int x = 0, int y = 0);
        void renderCenter(SDL_Texture* p_tex);
	    void display();
        void cleanUp();
        void clear();
        void viewPort();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
