#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    std::string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

    TransformComponent* transform;

    ColliderComponent() {}

    ColliderComponent(std::string t) {
        tag = t;
    }

    ~ColliderComponent() {}

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

		//tex = TextureManager::LoadTexture();

        Game::colliders.push_back(this);
    }

    void update() override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;

		destR.x = collider.x - 540 / 2;
		destR.y = collider.y - 960 / 2;
    }

	void draw() override {
		//TextureManager::Draw();
	}
};
