#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
    int width, height;

    int             cnt = 0;
    bool            isRunning = false;
    SDL_Window*     window;

	void create_desk();

public:

	static void AddTile(int srcX, int srcY, int xpos, int ypos);
    static SDL_Renderer*    renderer;
    static SDL_Event        event;
    static std::vector<ColliderComponent*> colliders;

    Game();
    ~Game();

    void    init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void    handleEvents();
    void    update();
    void    render();
    void    clean();

    bool    running() { return isRunning; };
};

#endif