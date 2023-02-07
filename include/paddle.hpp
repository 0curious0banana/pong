#pragma once
#include "Utils.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>


class Paddle
{
    public:
        Paddle(int i);
        void Update();
        void SetDir(int d);
        void IncScore();
        
        void ShowScore(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color);

        int GetId();
        Vec2 GetPos();
        SDL_Rect* GetRect();


    private:
        int id;
        int dir = 0;
        int height = 140;
        int width = 20;
        int score = 0;
        Vec2 pos;

        float speed;
        SDL_Rect rect;
        SDL_Rect scoreRect;
        SDL_Surface* ScoreSurface = nullptr;
        SDL_Texture* ScoreTexture = nullptr;
};