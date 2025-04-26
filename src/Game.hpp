#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    void tick(int framerate);

    bool running();

private:
    Uint32 frameStart;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif /* Game_hpp */