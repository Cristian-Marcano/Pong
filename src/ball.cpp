#include <raylib.h>
#include "ball.h"
#include "scoreBoard.h"

Ball::Ball() {
    this->pos = { 
        (float) GetScreenWidth() / 2, 
        (float) GetScreenHeight() / 2
    };

    this->speedX = (GetScreenWidth() + GetScreenHeight()) * 0.003;
    this->speedY = 0;

    this->radius = GetScreenHeight() / 48;
    this->border = 1;
}

void Ball::Draw() {
    //Boders
    DrawCircle(this->pos.x, this->pos.y, this->radius + this->border, this->colorBorder);
    //Circle
    DrawCircle(this->pos.x, this->pos.y, this->radius, this->colorBall);
}

void Ball::Update(ScoreBoard *score) {
    this->pos.x += this->speedX;
    this->pos.y += this->speedY;

    if(this->GetHitBallY() >= GetScreenHeight() || this->GetHitBallY() <= 0)
        this->speedY *= -1;
    if(this->GetHitBallX() >= GetScreenWidth() || this->GetHitBallX() <= 0) {
        if(this->GetHitBallX() <= 0) score->CPUPlusPoint();
        else score->UserPlusPoint();
        this->Reset();
    }
}

void Ball::UpdateForResizing(int screenWidth, int screenHeight) {
    this->pos.x *= (static_cast<float>(GetScreenWidth()) / screenWidth);
    this->pos.y *= (static_cast<float>(GetScreenHeight()) / screenHeight);

    this->speedX = ((this->speedX < 0) ? -1 : 1);
    this->speedX *= (GetScreenWidth() + GetScreenHeight()) * 0.003;

    this->radius = GetScreenHeight() / 48;
}

void Ball::Reset() {
    this->pos.x = GetScreenWidth() / 2;
    this->pos.y = GetScreenHeight() / 2;

    this->speedX = ((this->speedX < 0) ? -1 : 1);
    this->speedX *= (GetScreenWidth() + GetScreenHeight()) * 0.003;

    this->speedY = 0;
}


int Ball::GetHitBallX() {
    return (this->speedX < 0) ? this->pos.x - this->radius - this->border : this->pos.x + this->radius + this->border;
}

int Ball::GetHitBallY() {
    return (this->speedY < 0) ? this->pos.y - this->radius - this->border : this->pos.y + this->radius + this->border;
}

float Ball::GetX() {
    return this->pos.x;
}

float Ball::GetY() {
    return this->pos.y;
}

float Ball::GetRadius() {
    return this->radius + this->border;
}

int Ball::GetSpeedY() {
    return this->speedY;
}

int Ball::GetSpeedX() {
    return this->speedX;
}

void Ball::SetSpeedY(int potential, int direction) {
    this->speedY = direction * (GetScreenWidth() + GetScreenHeight()) / potential;
}

void Ball::SetSpeedX(int potential) {
    this->speedX = (GetScreenWidth() + GetScreenHeight()) / potential;
}