#pragma once

#include "Game.h"

class Map
{
private:
    int width, height;

    SDL_Rect    src, dest;

    SDL_Texture* desk;
    SDL_Texture* borts;
    SDL_Texture* goal;

    int map[20][25];
public:
    Map(int w, int h);
    ~Map();

    void    LoadMap(int arr[20][25]);
    void    DrawMap();
};
