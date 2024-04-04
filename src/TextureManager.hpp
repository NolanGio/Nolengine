#pragma once

#include "Game.hpp"
#include <iostream>
using namespace std;

class TextureManager {

public:
    static SDL_Texture *LoadTexture(SDL_Renderer* renderer, const char* imagePath, Uint32 r, Uint32 g, Uint32 b, Uint32 a);

};