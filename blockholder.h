#ifndef _BLOCK_HOLDER_H_
#define _BLOCK_HOLDER_H_

#include <vector>
#include "type.h"
#include "block.h"
#include "difficulty.h"
#include "levelzero.h"

class Grid;
class BlockHolder {
  Block currentBlock, nextBlock;

  std::vector<Difficulty*> levels;
  LevelZero levelZero;

  Grid *theGrid;

  Difficulty *getDifficulty(Level lvl);
  
public:
  BlockHolder(Grid *g);
  Block &getCurrentBlock();      // return the current block  
  Block &getNextBlock();         // return the type of next block
  void mutate(Move cmd, const int num = 1);   // mutate the current block
  void hint();                  // give hint for current block
  void generateNextBlock();     // sets the currentblock to the next block
  bool gameOver();              // return if the game is over
};

#endif
