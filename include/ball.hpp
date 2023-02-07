#pragma once
#include <SDL2/SDL_mixer.h>
#include "Utils.hpp"
#include "paddle.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "game.hpp"


class Ball
{
    public:
        Ball(class Game* g);
        void Update(Paddle* lPaddle, Paddle* rPaddle);
        void HandleCollision(Paddle* paddle);
        bool BottomCollision(Paddle* paddle);
        bool TopCollision(Paddle* paddle);
        void ShutDown();
        void reset();

        SDL_Rect* GetRect();

    private:
        int dir = 0;
        int size = 20;
        float speed;
        const int INITIAL_SPEED = 5.f;
        const int MAX_SPEED = 10.f;

        Vec2 pos;
        Vec2 vel;
        SDL_Rect rect;

        Mix_Chunk* sound = nullptr;

        Game* game;

};