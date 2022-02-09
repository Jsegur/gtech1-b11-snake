#pragma once

#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"
#include "Snake.hpp"

class Application {
    public:
        Application();
        ~Application();
        /*int Run(Unit32 frame_rate_ms);*/
    private:
};

class KeyBoard {
    public:
        void Input(bool running, Snake snake);
        void ReDirection(Snake snake, Snake::Direction input, Snake::Direction opposite);
        enum class Direction { kUp, kDown, kLeft, kRight };
    private:
};