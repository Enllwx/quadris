#ifndef _LEVEL_ONE_H_
#define _LEVEL_ONE_H_

#include "difficulty.h"

class LevelOne: public Difficulty{
public:
  LevelOne();
  LevelOne(std::shared_ptr<Grid> g, std::string load = "sequence.txt");
  Block newBlock() override;
  void setLoadPath(std::string path) override;
};

#endif
