#ifndef _BLOCK_HOLDER_H_
#define _BLOCK_HOLDER_H_

#include <vector>
#include "type.h"
#include "block.h"
#include "difficulty.h"
#include "levelzero.h"

class Grid;
class BlockHolder {
  Block currentBlock;

  std::vector<Difficulty*> levels;
  LevelZero levelZero;
  //Difficulty* levels[1] = {new LevelZero()};

  Grid *theGrid;

  Difficulty *getDifficulty(Level lvl);
  
public:
  BlockHolder(Grid *g);
  Block &getCurrentBlock();      // return the current block  
  Shape nextBlockType() const;  // return the type of next block
  void mutate(Move cmd, const int num = 1);   // mutate the current block
  void hint();                  // give hint for current block
  void clear();
  bool gameOver();              // return if the game is over
};

#endif
