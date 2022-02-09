#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>
#include "Snake.hpp"

void Snake::Update() {
  SDL_Point prev_segment{
      static_cast<int>(head_x), static_cast<int>(head_y)};
  UpdateHead();
  SDL_Point current_segment{
    static_cast<int>(head_x), static_cast<int>(head_y)};
  if (current_segment.x != prev_segment.x || current_segment.y != prev_segment.y) {
    UpdateBody(current_segment, prev_segment);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }
}

void Snake::UpdateBody(SDL_Point current_head_segment, SDL_Point prev_head_segment) {
  body.push_back(prev_head_segment);
  if (!growing) {
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }
  for (auto const &item : body) {
    if (current_head_segment.x == item.x && current_head_segment.y == item.y) {
      alive = false;
    }
  }
}
void Snake::GrowBody() { growing = true; }
bool Snake::Snake_segment(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}