#ifndef _LEVEL_FOUR_H_
#define _LEVEL_FOUR_H_

#include "difficulty.h"

class LevelFour: public Difficulty{
  int unclearedCounter;
public:
  LevelFour();
  LevelFour(std::shared_ptr<Grid> g, std::string load = "");
  Block newBlock() override;
  void implementPenalty() override;
};

#endif
