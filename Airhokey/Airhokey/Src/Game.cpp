#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map*            map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event     Game::event;

std::vector<ColliderComponent*> Game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& weapon(manager.addEntity());
auto& wall(manager.addEntity());
auto& goals(manager.addEntity());
auto& desk(manager.addEntity());

auto& tile0(manager.addEntity());

enum groupLabels : std::size_t {
	groupMap,
	groupPlayers,
	groupColliders
};

Game::Game() {}

Game::~Game() {}

void    Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

	this->width = width;
	this->height = height;

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


    map = new Map(width, height);

    //tile0.addComponent<TileComponent>(200, 200, 100, 100, 2);
    //tile0.addComponent<ColliderComponent>("tile0");

    player.addComponent<TransformComponent>(width / 2 - 50, height - height / 4 - 50, 100, 100, 1);
    player.addComponent<SpriteComponent>("assets/player1.png");
    player.addComponent<Controller>();
    player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

    enemy.addComponent<TransformComponent>(width / 2 - 50, height / 4 - 50, 100, 100, 1);
    enemy.addComponent<SpriteComponent>("assets/player2.png");
    //enemy.addComponent<Controller>();
    enemy.addComponent<ColliderComponent>("enemy");
	enemy.addGroup(groupPlayers);

    weapon.addComponent<TransformComponent>(width / 2 - 50, height / 2 - 50, 100, 100, 1);
    weapon.addComponent<SpriteComponent>("assets/weapon.png");
    //weapon.addComponent<Controller>();
    weapon.addComponent<ColliderComponent>("weapon");
	weapon.addGroup(groupPlayers);

	create_desk();
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

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));

void    Game::update() {
    manager.refresh();
    manager.update();

	/*for (auto cc : colliders) {
		if (Collision::AABB(player.getComponent<ColliderComponent>(), *cc)) {
			player.getComponent<TransformComponent>().velocity * -1;
			
		}
	}*/
	for (auto& t : tiles) {
		if (Collision::AABB(player.getComponent<ColliderComponent>(), 
			t->getComponent<ColliderComponent>())) {
			player.getComponent<TransformComponent>().velocity * -1;
		}
	}

	for (auto& p : players) {
		if (Collision::AABB(player.getComponent<ColliderComponent>(), 
			p->getComponent<ColliderComponent>())) {
			p->getComponent<TransformComponent>().velocity = player.getComponent<TransformComponent>().velocity;
			player.getComponent<TransformComponent>().velocity * -1;
		}
	}
}


void    Game::render() {
    SDL_RenderClear(renderer);

	for (auto& t : tiles) {
		t->draw();
	}

	for (auto& p : players) {
		p->draw();
	}

    SDL_RenderPresent(renderer);
}

void    Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}

void	Game::create_desk() {
	desk.addComponent<TransformComponent>(0.0f, 0.0f, width, height, 1);
	desk.addComponent<SpriteComponent>("assets/desk.png");
	desk.addComponent<ColliderComponent>("desk");
	desk.addGroup(groupMap);

	wall.addComponent<TransformComponent>(0.0f, 0.0f, width, 50, 1);
	wall.addComponent<SpriteComponent>("assets/bort.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.addGroup(groupMap);

	wall.addComponent<TransformComponent>(0.0f, height - 50.0f, width, 50, 1);
	wall.addComponent<SpriteComponent>("assets/bort.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.addGroup(groupMap);

	wall.addComponent<TransformComponent>(0.0f, 0.0f, 50, height, 1);
	wall.addComponent<SpriteComponent>("assets/bort.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.addGroup(groupMap);

	wall.addComponent<TransformComponent>(width - 50.30f, 0.0f, 50, height, 1);
	wall.addComponent<SpriteComponent>("assets/bort.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.addGroup(groupMap);

	goals.addComponent<TransformComponent>(width / 2 - 50.0f, 0.0f, 100, 50, 1);
	goals.addComponent<SpriteComponent>("assets/goal.png");
	goals.addComponent<ColliderComponent>("goals1");
	goals.addGroup(groupMap);

	goals.addComponent<TransformComponent>(width / 2 - 50.0f, height - 50.0f, 100, 50, 1);
	goals.addComponent<SpriteComponent>("assets/goal.png");
	goals.addComponent<ColliderComponent>("goals2");
	goals.addGroup(groupMap);
}

void	Game::AddTile(int srcX, int srcY, int xpos, int ypos) {
	auto& tile(manager.addEntity());
	//tile.addComponent<TileComponent>(x, y, 32, 32, id);
}


