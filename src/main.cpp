#include <raylib.h>
#include "stage.h"
#include "ball.h"
#include "paddles.h"
#include "scoreBoard.h"

void CheckCollisionPaddleAndBall(Ball*, Paddle*, int);

int main() {
    static int screenWidth = 1280, screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Ping Pong");
    
    SetWindowMinSize(854, 480);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);

    Stage *stage = new Stage(Color{20, 160, 133, 255},  Color{38, 185, 154, 255}, Color{129, 204, 184, 255});
    Ball *myBall = new Ball();
    Paddle *myPaddle = new Paddle(true);
    CPUPaddle *cpu = new CPUPaddle(false);
    ScoreBoard *score = new ScoreBoard();

    do {
        //* 1. Event Handling
        if(IsWindowResized()) {
            myPaddle->UpdateForResizing(screenHeight);
            cpu->UpdateForResizing(screenHeight);
            myBall->UpdateForResizing(screenWidth, screenHeight);
            score->UpdateForResizing();

            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }

        myPaddle->UpdateByKey();

        //* 2. Updating Position
        myBall->Update(score);
        cpu->Update((int) myBall->GetX(), (int) myBall->GetY(), myBall->GetSpeedX());

        //* 3. Check Collision 
        CheckCollisionPaddleAndBall(myBall, myPaddle, 1);
        CheckCollisionPaddleAndBall(myBall, cpu, -1);

        //* 4. Drawing
        BeginDrawing();
            stage->ClearStage();
            myBall->Draw();
            myPaddle->Draw();
            cpu->Draw();
            score->Draw();
        EndDrawing();
    } while (!WindowShouldClose());

    CloseWindow();
    return 0;
}

void CheckCollisionPaddleAndBall(Ball *ball, Paddle *paddle, int direction) {
    if(CheckCollisionCircleRec({ ball->GetX(), ball->GetY()}, ball->GetRadius(), {paddle->GetX(), paddle->GetY(), paddle->GetWidth(), paddle->GetHeight()})) {
        int potentialChoicesX[3] = { 500, 330, 250 };
        int potentialChoicesY[4] = { 500, 250, 200, 160 };

        int pChoiceX = GetRandomValue(1,2);
        int pChoiceY = GetRandomValue(1,3);

        if(paddle->GetLastMove() == 1) {
            ball->SetSpeedY(potentialChoicesY[pChoiceY], -1);
            ball->SetSpeedX(potentialChoicesX[pChoiceX] * direction);

        } else if(paddle->GetLastMove() == -1) {
            ball->SetSpeedY(potentialChoicesY[pChoiceY], 1);
            ball->SetSpeedX(potentialChoicesX[pChoiceX] * direction);

        } else {
            int speedChoices[2] = { 0, (ball->GetSpeedY() < 0) ? -1 : 1};

            int sChoice = GetRandomValue(0,1);
            pChoiceY = GetRandomValue(0,2);
            pChoiceX = GetRandomValue(0,2);

            ball->SetSpeedY(potentialChoicesY[pChoiceY], speedChoices[sChoice]);
            ball->SetSpeedX(potentialChoicesX[pChoiceX] * direction);
        }
    } 
}