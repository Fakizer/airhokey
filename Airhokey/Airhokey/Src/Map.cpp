#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map(int w, int h) {

    this->width = w;
    this->height = h;

    desk = TextureManager::LoadTexture("assets/desk.png");
    borts = TextureManager::LoadTexture("assets/bort.png");
    goal = TextureManager::LoadTexture("assets/goal.png");


    src.x = src.y = 0;
    dest.x = dest.y = 0;
    src.w = dest.w = 20;
    src.h = dest.h = 20;
}

Map::~Map() {
    SDL_DestroyTexture(desk);
    SDL_DestroyTexture(borts);
    SDL_DestroyTexture(goal);
}

void    Map::LoadMap(int arr[20][25]) {
    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {
            map[row][column] = arr[row][column];
        }
    }
}

void    Map::DrawMap() {
    int type = 0;

    TextureManager::Draw(desk, NULL, NULL, SDL_FLIP_NONE);
    SDL_Rect destR;
    destR.h = 50;
    destR.w = width;
    destR.x = destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR, SDL_FLIP_NONE);
    destR.h = 50;
    destR.w = width;
    destR.x = 0;
    destR.y = height - destR.h;
    TextureManager::Draw(borts, NULL, &destR, SDL_FLIP_NONE);
    destR.h = height;
    destR.w = 50;
    destR.x = 0;
    destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR, SDL_FLIP_NONE);
    destR.h = height;
    destR.w = 50;
    destR.x = width - destR.w;
    destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR, SDL_FLIP_NONE);


}
