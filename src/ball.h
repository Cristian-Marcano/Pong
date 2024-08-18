#pragma once
#include "scoreBoard.h"

class Ball {
  private:
    int radius, speedY, speedX, border;
    Vector2 pos;
    Color colorBall = Color{255, 255, 0, 255}, colorBorder = Color{255, 255, 255, 255};
  public: 
    Ball();
    ~Ball() { }

    void Draw();
    void Update(ScoreBoard*);
    void UpdateForResizing(int,int);
    void Reset();
    int GetHitBallX();
    int GetHitBallY();
    float GetX();
    float GetY();
    float GetRadius();
    int GetSpeedX();
    int GetSpeedY();
    void SetSpeedY(int,int);
    void SetSpeedX(int);
};