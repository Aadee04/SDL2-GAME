#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#define SDL_MAIN_HANDLED
#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 800

#include "RenderWindow.hpp"
#include "Entity.hpp"


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
    :window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x + (p_entity.getCurrentFrame().w - p_entity.getCurrentFrame().w*p_entity.getScale().x)/2;
	dst.y = p_entity.getPos().y + (p_entity.getCurrentFrame().h - p_entity.getCurrentFrame().h*p_entity.getScale().y)/2;
	dst.w = p_entity.getCurrentFrame().w*p_entity.getScale().x;
	dst.h = p_entity.getCurrentFrame().h*p_entity.getScale().y;

	SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getAngle(), 0, SDL_FLIP_NONE);
}

void RenderWindow::render(SDL_Texture* p_tex, int x, int y)
{

	SDL_Rect src; 
	src.x = 0;
	src. y = 0;

	SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::renderCenter(SDL_Texture* p_tex)
{

	SDL_Rect src; 
	src.x = 0;
	src. y = 0;

	SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = (WINDOW_WIDTH - src.w)/2;
	dst.y = (WINDOW_HEIGHT - src.h)/2;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::cleanUp() 
{
	SDL_DestroyWindow(window);
}

void RenderWindow::viewPort()
{
	SDL_RenderCopy( renderer, NULL, NULL, NULL );
}
