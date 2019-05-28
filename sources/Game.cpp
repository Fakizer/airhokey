#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Components.hpp"
#include "Collision.hpp"

Map*            map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event     Game::event;

std::vector<ColliderComponent*> Game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& weapon(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());

Game::Game() {}

Game::~Game() {}

void    Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsysten Initialised!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    SDL_Surface* tmpSurface = IMG_Load("resources/image.png");
    if (tmpSurface == NULL) {
        printf("IMG_Load: %s\n", IMG_GetError());
        exit(0);
    }
    map = new Map(width, height);

    tile0.addComponent<TileComponent>(200, 200, 100, 100, 2);
    tile0.addComponent<ColliderComponent>("tile0");

    player.addComponent<TransformComponent>(1);
    player.addComponent<SpriteComponent>("resources/player1.png");
    player.addComponent<Controller>();
    player.addComponent<ColliderComponent>("player");

    enemy.addComponent<TransformComponent>(1);
    enemy.addComponent<SpriteComponent>("resources/player2.png");
    // enemy.addComponent<Controller>();
    enemy.addComponent<ColliderComponent>("enemy");

    weapon.addComponent<TransformComponent>(1);
    weapon.addComponent<SpriteComponent>("resources/weapon.png");
    // weapon.addComponent<Controller>();
    weapon.addComponent<ColliderComponent>("weapon");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 100, 40, 1);
    wall.addComponent<SpriteComponent>("resources/bort.png");
    wall.addComponent<ColliderComponent>("wall");
}

void    Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type) {

    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void    Game::update() {
    manager.refresh();
    manager.update();

    if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
            wall.getComponent<ColliderComponent>().collider)) {
                std::cout << "wall hint" << std::endl;
                player.getComponent<TransformComponent>().velocity * -1.0f;
            }
}

void    Game::render() {
    SDL_RenderClear(renderer);
    // map->DrawMap();

    manager.draw();
    SDL_RenderPresent(renderer);
}

void    Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
