#include <raylib.h>
#include "stage.h"

Stage::Stage(Color bgColor1, Color bgColor2, Color bgColorCenter) {
    this->bgStage1 = bgColor1;
    this->bgStage2 = bgColor2;
    this->bgCenterStage = bgColorCenter;
}

void Stage::ClearStage() {
    ClearBackground(this->bgStage1);
    //* Stage CPU
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), this->bgStage2);
    //* Center 
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenHeight() / 4, bgCenterStage);
    //* Line
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
}