// AS Last Update: 12/12/22

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include <string>
#define SDL_MAIN_HANDLED
#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 800

#include "RenderWindow.hpp"
#include "Tile.hpp"
#include "Ball.hpp"
#include "Entity.hpp"
#include "Math.hpp"

using namespace std;


// Initializing various SDL components
void init() 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
		cout << "INIT_VIDEO FAILED, Error: " << SDL_GetError() << endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "SDL_image_PNG could not initialize! SDL_image Error: " << IMG_GetError() << endl;

    if (!( IMG_Init(IMG_INIT_JPG)))
        cout << "SDL_image_JPG could not initialize! SDL_image Error: " << IMG_GetError() << endl;

    return;
}


RenderWindow window("PORTALS 2D", WINDOW_WIDTH, WINDOW_HEIGHT);
// Creates the window


// Loading the Textures/Sounds/Colors
SDL_Texture* SpawnerTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/spawner-tile.png"); 
SDL_Texture* GoalTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/goal-tile.png"); 
SDL_Texture* BallTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/ball.png"); 
SDL_Texture* WallTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/wall-tile.png"); 
SDL_Texture* MagmaTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/magma-tile.png"); 
SDL_Texture* PortalBlue = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/portal-blue.png"); 
SDL_Texture* PortalGreen = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/portal-green.png"); 
SDL_Texture* WinTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/Win.png"); 
SDL_Texture* TitleTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/title.png"); 
SDL_Texture* bgTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/bg.jpg"); 
SDL_Texture* TitleBgTexture = window.loadTexture("C:/Users/aadee/Documents/Mini-Prj OOP/Code/res/gfx/bg.png"); 


// Global variables
bool gameRunning = true, passed = false, Start = false, levelPlay = false;
bool placed_blue = false, placed_green = false;

int green_x = WINDOW_WIDTH+50, green_y = WINDOW_HEIGHT+50;
int blue_x =  WINDOW_WIDTH+50, blue_y =  WINDOW_HEIGHT+50;
int levels = -1;

SDL_Event event;
Vector2f Spawner, Goal, BallPos;
std::vector<Tile>  tiles;
std::vector<Vector2f> WallPos, MagmaPos;
Tile B_portal = {Tile(Vector2f(blue_x, blue_y), PortalBlue)};
Tile G_portal = {Tile(Vector2f(green_x, green_y), PortalGreen)};
Ball ball = {Ball(BallPos, BallTexture)};


// Function to load the level
std::vector<Tile> loadTiles(int level)
{
    std::vector<Tile> temp = {};
    if(level < 3)
    {
        cout << "Level " + to_string(level + 1) << endl;

    }

    green_x = 1000, green_y = 1000;
    blue_x = 1000, blue_y = 1000;

	switch(level) 
	{
		case 0: // Level 1
            Spawner = Vector2f(50*6, 50*4);
            Goal = Vector2f(50*11, 50*4);

			temp.push_back(Tile(Vector2f(50*5, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*4), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*5), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*3), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*5), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*5), WallTexture));

			temp.push_back(Tile(Spawner, SpawnerTexture));
			temp.push_back(Tile(Goal, GoalTexture));

		break;

		case 1: // Level 2
            Spawner = Vector2f(50*6, 50*3);
            Goal = Vector2f(50*10, 50*7);

			temp.push_back(Tile(Vector2f(50*5, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*4), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*2), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*4), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*4), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*4), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*4), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*4), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*4), WallTexture));

            
			temp.push_back(Tile(Vector2f(50*5, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*8), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*6), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*8), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*8), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*8), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*8), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*8), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*8), WallTexture));

			temp.push_back(Tile(Spawner, SpawnerTexture));
			temp.push_back(Tile(Goal, GoalTexture));


		break;

		case 2: // Level 3
            Spawner = Vector2f(50*6, 50*2);
            Goal = Vector2f(50*10, 50*10);

			temp.push_back(Tile(Vector2f(50*5, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*3), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*1), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*3), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*3), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*1), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*2), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*3), WallTexture));

            
			temp.push_back(Tile(Vector2f(50*5, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*7), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*5), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*7), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*7), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*5), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*6), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*7), WallTexture));

            
			temp.push_back(Tile(Vector2f(50*5, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*10), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*10), MagmaTexture));
			temp.push_back(Tile(Vector2f(50*5, 50*11), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*9), WallTexture));

			temp.push_back(Tile(Vector2f(50*6, 50*11), WallTexture));
			temp.push_back(Tile(Vector2f(50*7, 50*11), WallTexture));
			temp.push_back(Tile(Vector2f(50*8, 50*11), WallTexture));
			temp.push_back(Tile(Vector2f(50*9, 50*11), WallTexture));
			temp.push_back(Tile(Vector2f(50*10, 50*11), WallTexture));

			temp.push_back(Tile(Vector2f(50*11, 50*9), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*10), WallTexture));
			temp.push_back(Tile(Vector2f(50*11, 50*11), WallTexture));

			temp.push_back(Tile(Spawner, SpawnerTexture));
			temp.push_back(Tile(Goal, GoalTexture));

		break;
	}

    BallPos.x = Spawner.x + 50;
    BallPos.y = Spawner.y;
    ball.setPos(BallPos.x, BallPos.y);

	return temp;
}


// Function to render the level once the components are made
void loadLevel(int level)
{
    cout << endl;
	tiles = loadTiles(level);
    WallPos.clear();
    MagmaPos.clear();
    window.clear();
    window.render(bgTexture, 0, 0);

    for(Tile T: tiles)
    {
        window.render(T);
        if (T.getTex() == WallTexture)
            WallPos.push_back(T.getPos());
        else if (T.getTex() == MagmaTexture)
            MagmaPos.push_back(T.getPos());
        window.display();
    }
}


// Collision physics for the ball and a portal
void Portal(Vector2f &moving)
{
    bool teleport = true;

    if(B_portal.getPos().x == moving.x + 50 && ball.getDirection() && B_portal.getPos().y == moving.y && placed_green)
    {
        
        for(Vector2f poss: WallPos)
        {
            if(poss.x == G_portal.getPos().x + 50 && poss.y == G_portal.getPos().y)
            {
                teleport = false;
                break;
            }
        }

        if(teleport)
        {    
            ball.setPos(G_portal.getPos().x + 50, G_portal.getPos().y);
            return;
        }
        
        ball.flip();
    return;
    }

    if(G_portal.getPos().x == moving.x + 50 && ball.getDirection() && G_portal.getPos().y == moving.y && placed_blue)
    {

        for(Vector2f poss: WallPos)
        {
            if(poss.x == B_portal.getPos().x + 50 && poss.y == B_portal.getPos().y)
            {
                teleport = false;
                break;
            }
        }

        if(teleport)
        {
            ball.setPos(B_portal.getPos().x + 50, B_portal.getPos().y);
            return;
        }
        
        ball.flip();
    return;
    }


    if(B_portal.getPos().x + 50 == moving.x && !ball.getDirection() && B_portal.getPos().y == moving.y && placed_green)
    {
        
        for(Vector2f poss: WallPos)
        {
            if(poss.x == G_portal.getPos().x - 50 && poss.y == G_portal.getPos().y)
            {
                teleport = false;
                break;
            }
        }

        if(teleport)
        {
            ball.setPos(G_portal.getPos().x - 50, G_portal.getPos().y);
            return;
        }
         
        ball.flip();
    return;
    }

    if(G_portal.getPos().x + 50 == moving.x && !ball.getDirection() && G_portal.getPos().y == moving.y && placed_green)
    {
        
        for(Vector2f poss: WallPos)
        {
            if(poss.x == B_portal.getPos().x - 50 && poss.y == B_portal.getPos().y)
            {
                teleport = false;
                break;
            }
        }

        if(teleport)
        {
            ball.setPos(B_portal.getPos().x - 50, B_portal.getPos().y);
            return;
        }
        
        ball.flip();
        return;
    }

    return;
}


// Function to reset the level to its initial state
void reset()
{
    cout << "Level has reset" << endl;
    B_portal.setPos(-100, -100);
    G_portal.setPos(-100, -100);
    loadLevel(levels);
    levelPlay = false;
    placed_blue = false;
    placed_green = false;
    if(!ball.getDirection())
        ball.flip();
}


// Function to check if the ball is out of bounds
void Out_Of_Bounds(Vector2f &moving)
{
    if(moving.x == -25 || moving.x == WINDOW_WIDTH+25)
    {
        cout << "Ball out of Bounds" << endl;
        reset();
    }

    return;
}


// Function that is called when the player starts playing
// Contains other collision detections for the ball and its environment
void Play() 
{
    window.clear();
    window.render(bgTexture, 0, 0);
    for(Tile T: tiles)
    {
        window.render(T);
    }
    ball.Movement();
    window.render(B_portal);
    window.render(G_portal);

    Vector2f moving = ball.getPos();

    if(Spawner.x  + 50 == moving.x && Spawner.y == moving.y)
    {
        ball.flip();
    }

    if((Goal.x-5 <= moving.x && Goal.x+55 >= moving.x ) && Goal.y == moving.y)
    {
        levelPlay = false;
        passed = true;
        return;
    }

    Portal(moving);

    for(Vector2f poss: MagmaPos)
    {
        if(poss.x == moving.x && poss.y == moving.y)
        {
            cout << "Encountered Magma" << endl;
            reset();
        }
    }

    for(Vector2f poss: WallPos)
    {
        if(poss.x - 5 == moving.x || poss.x == moving.x + 45)
        {
            if(poss.y == moving.y)
            {
                ball.flip();
            }
        }
    }

    Out_Of_Bounds(moving);

    window.render(ball);
    window.display();
}

void game() // Game function that is called when the game starts
{
    while(SDL_PollEvent(&event))
    {
        
        int mouse_x, mouse_y;
        
        if(passed) // Loads the next level
        {
            cout << endl << "Level Passed!" << endl; 
            levels++;
            Start = true;
            passed = false;
        }

        switch(event.type) // Taking inputs
        {
            case SDL_QUIT: // Window close (X) button
                gameRunning = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gameRunning = false;
                        break;
                    case SDLK_c: // clear screen
                        window.clear();
                        window.display();
                        break;
                    case SDLK_r: // reset the levels
                        reset();
                        break;
                    case SDLK_SPACE: // Places the ball and starts collison detection
                        levelPlay = true;
                        break;
                    case SDLK_o: // go back a level (developer tools)
                        levels -= 2;
                        passed = true;
                        break;
                    case SDLK_p: // advance a level (developer tools)
                        passed = true;
                        break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN: // Portal Placement logic
                SDL_GetMouseState(&mouse_x, &mouse_y);
                mouse_x = (mouse_x/50)*50;
                mouse_y = (mouse_y/50)*50;
                bool place = false;
                for(Vector2f pos: WallPos)
                {
                    if(pos.x == mouse_x && pos.y == mouse_y)
                    {
                        place = true;
                        break;
                    }
                }

                if(!place)
                    break;
                
                place = false;
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouse_x == green_x && mouse_y == green_y)
                        continue;
                    window.render(WallTexture, blue_x, blue_y);
                    placed_blue = true;
                    blue_x = mouse_x, blue_y = mouse_y;
                    B_portal.setPos(blue_x, blue_y);
                    window.render(B_portal);
                    window.display();
                }
                else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    if(mouse_x == blue_x && mouse_y == blue_y)
                        continue;
                    window.render(WallTexture, green_x, green_y);
                    placed_green = true;
                    green_x = mouse_x, green_y = mouse_y;
                    G_portal.setPos(green_x, green_y);
                    window.render(G_portal);
                    window.display();
                }
                break;
        }
    }

    if(Start)
    {
        loadLevel(levels);
        Start = false;
    }

    if(levelPlay) // Shows the current game screen as fast as possible
    {
        Play();
    }
    return;
}


void title(SDL_Texture* Tex) // Renders an image to the center of the screen
{
    int lvl = levels;
    window.clear();
    window.render(TitleBgTexture);
    window.renderCenter(Tex);
    window.display();
    while(levels == lvl)
    {
        while(SDL_PollEvent(&event)) // Press any button to play logic
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    levels++;
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
                case SDL_MOUSEBUTTONDOWN:
                    if(levels == -1 || levels == 3)
                        levels++;
                    break;
            }
        }
    }
    return;
}


// Main game function
int main(int argc, char* argv[])
{
    init();
	while (gameRunning) // continues till the game is over or player exits
	{
        if(levels < 0)
        {
            title(TitleTexture); // TitleScreen
            Start = true;
        }
        else if(levels < 3) // Levels
        {
		    game();
        }
        else
        {
            title(WinTexture); // Win Screen
            gameRunning = false;
        }
	}

    // SDL resource management
	window.cleanUp();
	SDL_Quit();

	return 0;
}