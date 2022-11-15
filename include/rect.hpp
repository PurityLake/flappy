#ifndef __FLAPPY_RECT_HPP__
#define __FLAPPY_RECT_HPP__

#include "flappy.hpp"

struct Rect {
    float x, y, w, h;
    
    Rect() : Rect(0.0f, 0.0f, 0.0f, 0.0f) { }
    Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) { }

    SDL_Rect *AsSDLRect() {
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        return &rect;
    }

private:
    SDL_Rect rect;
};

#endif /* __FLAPPY_RECT_HPP__ */