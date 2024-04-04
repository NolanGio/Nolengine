#include "Game.hpp"
#include "TextureManager.cpp"
#include <iostream>
using namespace std;



SDL_Texture *playerTex;
SDL_Rect srcR, destR;
int cnt;
string filePath;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL initialized\n";
        
        int flags = 0;
        if (fullscreen) 
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            cout << "Window initialized\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            cout << "Renderer initialized\n";
        }

        isRunning = true;
    } else {
        isRunning = false;
        cout << "Failed to initialize\n";
    }

    filePath = SDL_GetBasePath();

    playerTex = TextureManager::LoadTexture(renderer, "assets/player.png", 150, 0, 150, 255);
    destR.w = 8*5;
    destR.h = 25*5;
    destR.y = (WINDOW_HEIGHT - destR.h) / 2;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    cnt++;

    destR.x = cnt % (WINDOW_WIDTH + destR.w + 2) - destR.w;  

    cout << cnt << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    // Drawing takes place here
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    // End of drawing
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "SDL closed successfully\n";
}

bool Game::running()
{
    return isRunning;
}