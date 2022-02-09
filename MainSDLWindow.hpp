#pragma once
#include <SDL2/SDL.h>

class MainSDLWindow {
  public:
    MainSDLWindow();
    ~MainSDLWindow();
    SDL_Renderer* GetRenderer();
    int Init(const char* name, int width_, int height_);
    void UpdateWindowTitle(int score, int fps);
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};