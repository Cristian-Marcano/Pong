#include <raylib.h>
#include <iostream>
#include "stage.h"
#include "ball.h"
#include "paddles.h"

int main() {

    static int screenWidth = 1280, screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Ping Pong");
    
    SetWindowMinSize(854, 480);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);

    Stage *stage = new Stage(Color{20, 160, 133, 255},  Color{38, 185, 154, 255}, Color{129, 204, 184, 255});
    Ball *myBalls = new Ball();
    Paddles *myPaddles = new Paddles(true);

    do {
        //* 1. Event Handling
        if(IsWindowResized()) {
            myPaddles->UpdateForResizing(screenHeight);
            myBalls->UpdateForResizing(screenWidth, screenHeight);
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }

        myPaddles->UpdateByKey();

        //* 2. Updating Position
        myBalls->Update();

        //* 3. Check Collision 
        // if(CheckCollisionCircleRec())

        //* 4. Drawing
        BeginDrawing();
            stage->ClearStage();
            myBalls->Draw();
            myPaddles->Draw();
        EndDrawing();
    } while (!WindowShouldClose());

    CloseWindow();
    return 0;
}