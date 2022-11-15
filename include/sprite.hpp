#ifndef __FLAPPY_SPRITE_HPP__
#define __FLAPPY_SPRITE_HPP__

#include "flappy.hpp"

class Sprite {
 private:
  std::string path;
  SDL_Texture* tex;

  void init(SDL_Renderer* renderer);

 public:
  Sprite();
  Sprite(SDL_Renderer* renderer, const std::string& path);
  Sprite(SDL_Renderer* renderer, std::string&& path);
  Sprite(const Sprite& other);
  Sprite(const Sprite&& other);
  virtual ~Sprite();

  Transform transform;

  void Destroy();

  void Render(SDL_Renderer* renderer);
};

#endif /* __FLAPPY_SPRITE_HPP__ */