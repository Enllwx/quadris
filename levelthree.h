#ifndef _LEVEL_THREE_H_
#define _LEVEL_THREE_H_

#include "difficulty.h"

class LevelThree: public Difficulty{
public:
  LevelThree();
  LevelThree(std::shared_ptr<Grid> g, std::string load = "");
  Block newBlock() override;
};

#endif
