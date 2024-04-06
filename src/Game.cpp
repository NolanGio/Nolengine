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
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    if (SDL_Init(SDL_INIT_EVERYTHING^SDL_INIT_HAPTIC) == 0)
    {
        int flags = 0;
        if (fullscreen) 
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (!window)
        {
            cout << "Window failed to initialize\n";
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (!renderer)
        {
            cout << "Renderer failed to initialize\n";
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }

        playerTex = TextureManager::LoadTexture(renderer, "assets/player.png", 150, 0, 150, 255);
        if (!playerTex)
        {
            cout << "Texture failed to load\n";
        }

        destR.w = 8*5;
        destR.h = 25*5;
        destR.y = (WINDOW_HEIGHT - destR.h) / 2;

        isRunning = true;
    } else {
        isRunning = false;
        cout << "Error : " << SDL_GetError();
    }

    
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

    cout << cnt << "\n";

    destR.x = cnt % (WINDOW_WIDTH + destR.w + 2) - destR.w;  
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

int Game::tick(int framerate)
{
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    Uint32 frameDelay = 1000/framerate;

    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }

    frameStart = SDL_GetTicks();
}

bool Game::running()
{
    return isRunning;
}