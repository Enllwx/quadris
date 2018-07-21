#ifndef _LEVEL_TWO_H_
#define _LEVEL_TWO_H_

#include "difficulty.h"

class LevelTwo: public Difficulty{
public:
  LevelTwo();
  LevelTwo(std::shared_ptr<Grid> g, std::string load = "sequence.txt");
  Block newBlock() override;
  void setLoadPath(std::string path) override;
};

#endif
