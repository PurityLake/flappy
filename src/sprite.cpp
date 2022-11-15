#include "sprite.hpp"

// Sprite(std::string&& path);
// Sprite(const Sprite& other);
// Sprite(const Sprite&& other);

// void SetImage(const std::string& path);

Sprite::Sprite() { }

Sprite::~Sprite() {
    if (tex) {
        SDL_DestroyTexture(tex);
        tex = NULL;
    }
}

Sprite::Sprite(SDL_Renderer *renderer, const std::string& path) {
    init(renderer, path);
}

void Sprite::init(SDL_Renderer *renderer, const std::string& path) {
    if (tex != NULL) {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Destroying the texture of a sprite already created.\n");
        SDL_DestroyTexture(tex);
    }

    SDL_Surface *loadedSurf = IMG_Load(path.c_str());
    if (!loadedSurf) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to loaed image '%s': %s\n", path.c_str(), IMG_GetError());
        return;
    }
    
    tex = SDL_CreateTextureFromSurface(renderer, loadedSurf);
    if (!tex) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create texture from surface: %s\n", SDL_GetError());
        return;
    }

    SDL_FreeSurface(loadedSurf);
}

void Sprite::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, tex, NULL, NULL);
}