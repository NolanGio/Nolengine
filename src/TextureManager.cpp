#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(SDL_Renderer *renderer, const char *imagePath, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
    string filePath = SDL_GetBasePath();
    SDL_Surface *tmpSurf = IMG_Load((filePath + imagePath).c_str());
    
    if (a != 0)
    {
        SDL_SetColorKey(tmpSurf, SDL_TRUE, SDL_MapRGBA(tmpSurf->format, r, g, b, a));
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, tmpSurf);
    SDL_FreeSurface(tmpSurf);
    return tex;
}