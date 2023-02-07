#include "Paddle.hpp"
#include <string>

Paddle::Paddle(int i) {
    id = i;
    speed = 20.f;

    if (id == 0) {
        pos.x = 0;
        
    }
    else if (id == 1) {
        pos.x = SCREEN_WIDTH - width;
    }

    pos.y = SCREEN_HEIGHT / 2 - height / 2;

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
    rect.w = width;
    rect.h = height;
}

void Paddle::Update() {
    pos.y = pos.y + speed * dir;
    
    if (pos.y < 0) {
        pos.y = 0;
    }
    else if (pos.y + height > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - height;
    }

    rect.y = pos.y;
}

void Paddle::SetDir(int d) {
    dir = d;
}

void Paddle::IncScore() {
    score++;
}

void Paddle::ShowScore(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color) {
    ScoreSurface = TTF_RenderText_Solid(font, to_string(score).c_str(), color);

    if (id == 0) {
        scoreRect.x = SCREEN_WIDTH / 2 - 100;
    }
   if (id == 1) {
        scoreRect.x = SCREEN_WIDTH / 2 + 100;
    }
    scoreRect.y = 50;
    scoreRect.w = ScoreSurface->w;
    scoreRect.h = ScoreSurface->h;
    ScoreTexture = SDL_CreateTextureFromSurface(renderer, ScoreSurface);
    SDL_RenderCopy(renderer, ScoreTexture, NULL, &scoreRect);

}

int Paddle::GetId() {
    return id;
}


Vec2 Paddle::GetPos() {
    return pos;
}

SDL_Rect* Paddle::GetRect() {
    return &rect;
}
