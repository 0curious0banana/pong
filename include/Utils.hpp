#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>


using namespace std;

const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 800;

struct Vec2 {
    float x;
    float y;
};