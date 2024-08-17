#include <raylib.h>
#include "scoreBoard.h"

ScoreBoard::ScoreBoard() {
    this->posUserPoints = {
        (float) (GetScreenWidth() / 4) - 20,
        20
    };

    this->posCPUPoints = {
        (float) 3 * (GetScreenWidth() / 4) - 20,
        20
    };

    this->fontSize = 80;
}

void ScoreBoard::Draw() {
    DrawText(TextFormat("%d", this->userPoints), this->posUserPoints.x, this->posUserPoints.y, this->fontSize, WHITE);
    DrawText(TextFormat("%d", this->cpuPoints), this->posCPUPoints.x, this->posCPUPoints.y, this->fontSize, WHITE);
}

void ScoreBoard::UpdateForResizing() {
    this->posUserPoints.x = (float) (GetScreenWidth() / 4) - 20;
    this->posCPUPoints.x = (float) 3 * (GetScreenWidth() / 4) -20;
}

void ScoreBoard::UserPlusPoint() {
    this->userPoints++;
}

void ScoreBoard::CPUPlusPoint() {
    this->cpuPoints++;
}