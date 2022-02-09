#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"

bool gameOver;

MainSDLWindow::MainSDLWindow() {
    this->renderer = NULL;
    this->window = NULL;
}

MainSDLWindow::~MainSDLWindow() {
    if(this->renderer != NULL) SDL_DestroyRenderer(this->renderer = NULL);
    if(this->window != NULL) SDL_DestroyWindow(this->window = NULL);
    SDL_Quit();
}

SDL_Renderer *MainSDLWindow::GetRenderer() {
    return this->renderer;
}

int input(void){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
    switch (event.type){
        case SDL_QUIT:
        gameOver = true;
        break;
        }
    }
}

int main(void){
    MainSDLWindow sdlwin;
    sdlwin.Init("Snake", 800, 600);
    while (!gameOver){
    input();
    }
}

int MainSDLWindow::Init(const char* name, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    Uint32 window_flags = SDL_WINDOW_RESIZABLE; 
    this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, window_flags);
    if(this->window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    this->renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (this->renderer == NULL) {
        printf("SDL2 error while creating renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
    return EXIT_SUCCESS;
}

void MainSDLWindow::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(window, title.c_str());
}
