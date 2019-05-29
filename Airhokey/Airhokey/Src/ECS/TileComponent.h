#pragma once

#include "Components.h"
#include "SDL.h"
#include <cstring>

class TileComponent : public Component {
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    SDL_Rect tileRect;
    int tileID;
    const char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.h = h;
        tileRect.w = w;
        tileID = id;

        switch (tileID)
        {
        case 0: 
            path = "assets/desk.png";
            break;
        case 1:
            path = "assets/bort.png";
            break;
        case 2:
            path = "assets/goal.png";
            break;
        default:
            break;
        }
    }

    void    init() override {
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, (float)tileRect.w, (float)tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        std::cout << path << std::endl << std::endl;

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
