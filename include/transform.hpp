#ifndef __FLAPPY_RECT_HPP__
#define __FLAPPY_RECT_HPP__

#include "flappy.hpp"

struct Transform {
  float x, y, w, h, rot;

  Transform() : Transform(0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {}
  Transform(float x, float y, float w, float h, float rot)
      : x(x), y(y), w(w), h(h), rot(rot) {}

  SDL_Rect* AsSDLRect() {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    return &rect;
  }

  SDL_Point* Center() {
    center.x = rect.x + rect.w / 2.0f;
    center.y = rect.y + rect.h / 2.0f;
    return &center;
  }

 private:
  SDL_Rect rect;
  SDL_Point center;
};

#endif /* __FLAPPY_RECT_HPP__ */