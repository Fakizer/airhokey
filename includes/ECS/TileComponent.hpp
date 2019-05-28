#pragma once

#include "Components.hpp"
#include "SDL2/SDL.h"
#include <cstring>

class TileComponent : public Component {
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    SDL_Rect tileRect;
    int tileID;
    char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.h = h;
        tileRect.w = w;
        tileID = id;

        switch (tileID)
        {
        case 0: {
            std::string s("resources/desk.png");
            path = new char[s.length() + 1];
            strcpy(path, s.c_str());
            // path[s.length() + 1] = static_cast<char*>("resources/desk.png");
        }
            break;
        case 1: {
            std::string s("resources/bort.png");
            path = new char[s.length() + 1];
            strcpy(path, s.c_str());
            // path = static_cast<char*>("resources/bort.png");
        }
            break;
        case 2: {
            std::string s("resources/goal.png");
            path = new char[s.length() + 1];
            strcpy(path, s.c_str());
            // path = static_cast<char*>("resources/goal.png");
        }
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
