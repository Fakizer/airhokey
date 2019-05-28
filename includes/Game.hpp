#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
    int width, height;

    int             cnt = 0;
    bool            isRunning = false;
    SDL_Window*     window;
    SDL_Event*      mainEvent;

    void    create_window();
    void    resize_window();
public:

    static SDL_Renderer*    renderer;
    static SDL_Event        event;
    static std::vector<ColliderComponent*> colliders;

    Game();
    ~Game();
    void    set_width(int w);
    void    set_height(int h);
    int     get_width() const;
    int     get_height() const;

    void    init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void    handleEvents();
    void    update();
    void    render();
    void    clean();

    bool    running() { return isRunning; };
};

#endif