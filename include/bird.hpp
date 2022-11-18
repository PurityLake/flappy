#ifndef __FLAPPY_BIRD_HPP__
#define __FLAPPY_BIRD_HPP__

#include "entity.hpp"
#include "sprite.hpp"

class Bird : public Entity {
private:
    const std::string filename = "assets/sprites/flapper.png";
    Sprite sprite;
    float gravity = 9.8f;

public:
    Bird() = delete;
    Bird(SDL_Renderer *renderer) : sprite(renderer, filename) {
        sprite.transform.x = 30;
        sprite.transform.y = 40;
        sprite.transform.w = 64;
        sprite.transform.h = 64;
        sprite.transform.rot = 0;
    }

    virtual ~Bird() {
        sprite.Destroy();
    }

    virtual void Update(float dt) {
        sprite.transform.y += gravity * 0.01f;
    }

    void Render(SDL_Renderer *renderer) {
        sprite.Render(renderer);
    }

    Transform& GetTransform() {
        return sprite.transform;
    }
};

#endif /* __FLAPPY_BIRD_HPP__ */