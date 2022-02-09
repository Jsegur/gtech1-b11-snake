#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>
#include "Application.hpp"
#include "Snake.hpp"

void KeyBoard::ReDirection(Snake snake, Snake::Direction input, Snake::Direction opposite){
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void KeyBoard::Input(bool running, Snake snake) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {  
    if (event.type == SDL_QUIT) {
      running = false;
    }
    else if (event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym) {
      case SDLK_UP:
        ReDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
        break;
      case SDLK_DOWN:
        ReDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
        break;
      case SDLK_LEFT:
        ReDirection(snake, Snake::Direction::kLeft, Snake::Direction::kRight);
        break;
      case SDLK_RIGHT:
        ReDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);
        break;
      }
    }
  }
}

/*void Application::Run(Unit32 frame_rate_ms) {

  Uint32 frame_rate = 0;
  Uint32 frame_time_start = SDL_GetTicks();
  Uint32 frame_time_interval;
  bool run = true

  while (run) {
    frame_time_start = SDL_GetTicks();

    KeyBoard.Input(running, snake);
    Update();
    renderer.Render(snake, food);

    Run++;
    frame_time_interval = SDL_GetTicks() - frame_time_start;

    if (SDL_GetTicks() - frame_time_start >= 1000) {
    renderer.UpdateWindowTitle(score, frame_rate);
    frame_rate = 0;
    frame_time_start = SDL_GetTicks();
    }
        
    SDL_Delay(frame_time_interval);        
    }
}*/