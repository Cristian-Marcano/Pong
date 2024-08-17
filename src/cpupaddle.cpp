#include <raylib.h>
#include "paddles.h"

void CPUPaddle::Update(int ballX, int ballY, int speedX) {
    int ramdom = GetRandomValue(1, 4);

    if(ballX > GetScreenWidth() / 2 && speedX > 0 && ramdom < 4) {
        if(this->pos.y + (this->height / 2) > ballY) {
            this->pos.y -= this->speed;
            this->lastMove = 1;
        }
        if(this->pos.y + (this->height / 2) <= ballY) {
            this->pos.y += this->speed;
            this->lastMove = -1;
        }
    
        this->LimitMovement(); 
    }
}

void CPUPaddle::UpdateForResizing(int screenHeight) {
    this->height = GetScreenHeight() / 8;

    this->pos.y = GetScreenHeight() * (this->pos.y / screenHeight);

    this->speed = (GetScreenWidth() + GetScreenHeight()) * 0.006;

    this->pos.x = GetScreenWidth() - this->width - 3;
}