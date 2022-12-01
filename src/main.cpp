#include <string>
#
#include "bird.hpp"

int main(int argc, char* argv[]) {
  --argc;
  ++argv;

  int windowWidth = 640;
  int windowHeight = 480;

  if (argc == 2) {
    windowWidth = atoi(argv[0]);
    windowHeight = atoi(argv[1]);
  }

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s",
                 SDL_GetError());
    return 3;
  }

  if (SDL_CreateWindowAndRenderer(windowWidth, windowHeight,
                                  SDL_WINDOW_RESIZABLE, &window, &renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't create window and renderer: %s", SDL_GetError());
    return 3;
  }

  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't start SDL Image: %s\n",
                 IMG_GetError());
    return 3;
  }

  Bird bird{renderer};

  while (1) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      break;
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    bird.Render(renderer);

    SDL_RenderPresent(renderer);

    //bird.Update(0.1f);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}