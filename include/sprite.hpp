#ifndef __FLAPPY_SPRITE_HPP__
#define __FLAPPY_SPRITE_HPP__

#include <string>

#include <SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
private:
    SDL_Rect rect;
    SDL_Texture *tex;

    void init(SDL_Renderer *renderer, const std::string& path);

public:
    Sprite();
    Sprite(SDL_Renderer *renderer, const std::string& path);
    // Sprite(std::string&& path);
    // Sprite(const Sprite& other);
    // Sprite(const Sprite&& other);
    virtual ~Sprite();

    // void SetImage(const std::string& path);
    
    void Render(SDL_Renderer *renderer);
};

#endif /* __FLAPPY_SPRITE_HPP__ */