#include <iostream>
#include <vector>
#include <cmath>
#include <SDL3/SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "spdlog/spdlog.h"
#include <memory>
#include "Player.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
int main(int argc, char **argv)
{
    // Initializiation
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("Initializing SDL...");
    if (!SDL_Init(SDL_INIT_VIDEO))
        spdlog::critical("Failed to initialize SDL.");
    else
        spdlog::info("Initialized SDL");
    IMGUI_CHECKVERSION();
    // SDL_Window *gameplayWindow = SDL_CreateWindow("Raycasing showcase", 1000, 800, SDL_WINDOW_OPENGL);
    // SDL_Renderer *gameplayRenderer = SDL_CreateRenderer(gameplayWindow, NULL);
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> rayViewer(SDL_CreateWindow("Ray viewer", RV_WIDTH, RV_HEIGHT, SDL_WINDOW_OPENGL), &SDL_DestroyWindow);
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> rayRenderer(SDL_CreateRenderer(rayViewer.get(), NULL), &SDL_DestroyRenderer);
    SDL_Event e;
    bool running = true;
    return 0;
}