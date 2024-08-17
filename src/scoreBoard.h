#pragma once

class ScoreBoard {
  private:
    int userPoints = 0, cpuPoints = 0, fontSize;
    Vector2 posUserPoints, posCPUPoints;
  public:
    ScoreBoard();
    ~ScoreBoard() { }

    void Draw();
    void UpdateForResizing();
    void UserPlusPoint();
    void CPUPlusPoint();
};