#pragma once

class Stage {
  private:
    Color bgStage1 , bgStage2, bgCenterStage;
  public:
    Stage(Color, Color, Color);
    ~Stage() { }

    void ClearStage();
};