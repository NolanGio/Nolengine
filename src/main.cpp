#include "Game.cpp"

Game *game = new Game();

int main(int argv, char** args)
{
    game->init("Nolengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 250, 250, false);
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();

        game->tick(60);
    }
    
    game->clean();
    return 0;
}