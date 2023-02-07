#pragma once
#include "Utils.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

enum Gamestates {
    Pending,
    Playing
};

class Game
{
public:
    bool Init();
    void GameLoop();
    void ShutDown();

    void SetGameStatePending();

private:
    void HandleEvents();
    void Update();
    void Draw();
    bool isRunning = true;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    class Paddle* leftPaddle, * rightPaddle;
    class Ball* ball;
    int gamestate = Gamestates::Pending;

    TTF_Font* font = nullptr;
    SDL_Color fontColor = {255, 255, 255};
};
