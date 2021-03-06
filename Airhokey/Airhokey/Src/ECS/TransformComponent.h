#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component {
public:

    Vector2D position;
    Vector2D velocity;

    int width = 32, height = 32;
    int scale = 1;

    float speed = 1;

    TransformComponent() {
        position.Zero();
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent(int sc) {
        position.Zero();
        scale = sc;
    }

    TransformComponent(float x, float y, int w, int h, int sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override {
        velocity.Zero();
    }
    void update() override {
        position += velocity * speed;
    }

};