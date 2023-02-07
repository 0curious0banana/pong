#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "game.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[]) {
    Game game;

    if (game.Init()) {
        game.GameLoop();
    }

    game.ShutDown();

    
    return 0;
}
