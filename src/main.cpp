#include "Game.cpp"
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif



Game *game = new Game();
void mainloop();

int main(int argv, char** args)
{
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop(mainloop, 0, 1);
    #else
    game->init("Nolengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    while (game->running())
    {
        mainloop();
    }
    #endif

    return 0;
}

void mainloop()
{
    if (!game->running())
    {
        game->init("Nolengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    }

    Uint32 frameStart;
    int frameTime;

    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }

    if (!game->running())
    {
        #ifdef EMSCRIPTEN
        emscripten_cancel_main_loop();
        #endif
        
        game->clean();
    }
}