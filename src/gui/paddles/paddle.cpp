#include <raylib.h>
#include "paddles.h"

Paddle::Paddle(bool pos) {
    this->width = GetScreenWidth() / 100;
    this->height = GetScreenHeight() / 8;

    this->pos = {
        (float) ((pos) ? 3 : GetScreenWidth() - this->width - 3), 
        (float) (GetScreenHeight() - this->height) / 2
    };

    this->speed = (GetScreenWidth() + GetScreenHeight()) * 0.006;
}

void Paddle::Draw() {
    DrawRectangleRounded(Rectangle{this->pos.x, this->pos.y, this->width, this->height}, 0.8, 0, WHITE);
}

void Paddle::UpdateByKey() {
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        this->pos.y -= this->speed;
        this->lastMove = 1;
        this->countFrame = 0;
    } else if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        this->pos.y += this->speed;
        this->lastMove = -1;
        this->countFrame = 0;
    } else if(this->countFrame == 5)
        this->lastMove = 0;

    this->countFrame += (this->countFrame < 5) ? 1 : -5;

    this->LimitMovement();
}

void Paddle::UpdateForResizing(int screenHeight) {
    this->height = GetScreenHeight() / 8;

    this->pos.y = GetScreenHeight() * (this->pos.y / screenHeight);

    this->speed = (GetScreenWidth() + GetScreenHeight()) * 0.006;
}

void Paddle::LimitMovement() {
    if(this->pos.y <= 0) 
        this->pos.y = 0;

    if(this->pos.y + this->height >= GetScreenHeight())
        this->pos.y = GetScreenHeight() - this->height;
}

float Paddle::GetX() {
    return this->pos.x;
}

float Paddle::GetY() {
    return this->pos.y;
}

float Paddle::GetWidth() {
    return this->width;
}

float Paddle::GetHeight() {
    return this->height;
}

int Paddle::GetLastMove() {
    return this->lastMove;
}