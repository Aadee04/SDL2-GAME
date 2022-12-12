#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Tile.hpp"
#include "Entity.hpp"
#include "Math.hpp"


Tile::Tile(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex)
{
}
