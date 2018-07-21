#ifndef _LEVEL_ZERO_H_
#define _LEVEL_ZERO_H_

#include "difficulty.h"

class LevelZero: public Difficulty{
public:
  LevelZero();
  LevelZero(std::shared_ptr<Grid> g, std::string load = "sequence.txt");
  Block newBlock() override;
  void setLoadPath(std::string path) override;
};

#endif
