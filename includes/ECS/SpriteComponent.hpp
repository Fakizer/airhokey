#pragma once

#include "Components.hpp"
#include "SDL2/SDL.h"
#include "TextureManager.hpp"

class SpriteComponent : public Component {
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTex(path);
    }
    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }

    void    setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void    init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.h = transform->height;
        srcRect.w = transform->width;
        srcRect.x = 0;
        srcRect.y = 0;

        // destRect.w = srcRect.w * 2;
        // destRect.h = srcRect.h * 2;

        destRect.w = srcRect.w;
        destRect.h = srcRect.h;
    }

    void    update() override {
        // std::cout << (int)transform->position.x << "," << (int)transform->position.y << std::endl;
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void    draw() override {
        // std::cout << "asdasd" << std::endl;
        // TextureManager::Draw(texture, &srcRect, &destRect);
        TextureManager::Draw(texture, NULL, &destRect);
    }
};