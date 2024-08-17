#pragma once

class Paddle {
  protected:
    void LimitMovement();
    int speed, lastMove, countFrame = 0;
    float width, height;
    Vector2 pos;
  public: 
    Paddle(bool);
    ~Paddle() { }

    void Draw();
    void UpdateByKey();
    virtual void UpdateForResizing(int);
    float GetX();
    float GetY();
    float GetWidth();
    float GetHeight();
    int GetLastMove();
};

class CPUPaddle: public Paddle {
  public:
    CPUPaddle(bool pos): Paddle(pos) { };
    ~CPUPaddle() { }

    void Update(int,int,int);
    void UpdateForResizing(int) override;
};