#include "Map.hpp"
#include "TextureManager.hpp"

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

    desk = TextureManager::LoadTexture("resources/desk.png");
    borts = TextureManager::LoadTexture("resources/bort.png");
    goal = TextureManager::LoadTexture("resources/goal.png");

    LoadMap(lvl1);

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

    TextureManager::Draw(desk, NULL, NULL);
    SDL_Rect destR;
    destR.h = 50;
    destR.w = width;
    destR.x = destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR);
    destR.h = 50;
    destR.w = width;
    destR.x = 0;
    destR.y = height - destR.h;
    TextureManager::Draw(borts, NULL, &destR);
    destR.h = height;
    destR.w = 50;
    destR.x = 0;
    destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR);
    destR.h = height;
    destR.w = 50;
    destR.x = width - destR.w;
    destR.y = 0;
    TextureManager::Draw(borts, NULL, &destR);
    // for (int row = 0; row < 20; row++) {
    //     for (int column = 0; column < 25; column++) {
    //         type = map[row][column];
            
    //         dest.x = column * 20;
    //         dest.y = row * 20;
    //         switch (type)
    //         {
    //         case 0:
    //             TextureManager::Draw(desk, &src, &dest);
    //             break;
    //         case 1:
    //             TextureManager::Draw(borts, &src, &dest);
    //             break;
    //         case 2:
    //             TextureManager::Draw(goal, &src, &dest);
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    // }
}
