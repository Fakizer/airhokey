#pragma once

#include "Game.h"

class TextureManager {
private:
    /* data */
public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void         Draw(SDL_Texture* tex, const SDL_Rect * src, const SDL_Rect * dest, SDL_RendererFlip flip);
};
