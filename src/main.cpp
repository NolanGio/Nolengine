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
    game->init("Nolengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 250, 250, false);
    while (game->running())
    {
        mainloop();
    }
    #endif

    return 0;
}

void mainloop()
{
    #ifdef EMSCRIPTEN
    if (!game->running())
    {
        game->init("Nolengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 250, 250, false);
    }
    #endif

    game->handleEvents();
    game->update();
    game->render();

    if (!game->running())
    {
        #ifdef EMSCRIPTEN
        emscripten_cancel_main_loop();
        #endif
        
        game->clean();
    }

    game->tick(60);
}