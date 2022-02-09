#pragma once
#include <SDL2/SDL.h>
#include <vector>

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int width, int height): 
        width(width),
        height(height),
        head_x(width / 2),
        head_y(height / 2) {}
  void Update();
  void GrowBody();
  bool Snake_segment(int x, int y);
  Direction direction = Direction::kUp;
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
 private:
  void UpdateHead();
  void UpdateBody(SDL_Point current_segment, SDL_Point prev_securrent_segment);
  bool growing{false};
  int width;
  int height;
};