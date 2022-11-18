#include "sprite.hpp"

Sprite::Sprite(SDL_Renderer* renderer, const std::string& path) : path(path) {
  init(renderer);
}

Sprite::Sprite(SDL_Renderer* renderer, std::string&& path) : path(path) {
  init(renderer);
}

Sprite::Sprite(const Sprite& other) {
  Destroy();
  path = other.path;
  tex = other.tex;
  transform = other.transform;
}

Sprite::Sprite(const Sprite&& other) {
  Destroy();
  path = other.path;
  tex = other.tex;
  transform = other.transform;
}

// void SetImage(const std::string& path);

Sprite::Sprite() {}

Sprite::~Sprite() {
  Destroy();
}

void Sprite::Destroy() {
  if (tex) {
    SDL_DestroyTexture(tex);
    tex = NULL;
  }
}

void Sprite::init(SDL_Renderer* renderer) {
  if (tex != NULL) {
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
                 "Destroying the texture of a sprite already created.\n");
    SDL_DestroyTexture(tex);
  }

  SDL_Surface* loadedSurf = IMG_Load(path.c_str());
  if (!loadedSurf) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to loaed image '%s': %s\n", path.c_str(),
                 IMG_GetError());
    return;
  }

  tex = SDL_CreateTextureFromSurface(renderer, loadedSurf);
  if (!tex) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to create texture from surface: %s\n", SDL_GetError());
    return;
  }

  SDL_FreeSurface(loadedSurf);
}

void Sprite::Render(SDL_Renderer* renderer) {
  SDL_RenderCopyEx(renderer, tex, NULL, transform.AsSDLRect(), transform.rot,
                   transform.Center(), SDL_FLIP_NONE);
}