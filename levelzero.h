#ifndef _LEVEL_ZERO_H_
#define _LEVEL_ZERO_H_

#include "difficulty.h"

class LevelZero: public Difficulty{
public:
  LevelZero(Grid *g = nullptr);
  Block newBlock() override;
};

#endif
