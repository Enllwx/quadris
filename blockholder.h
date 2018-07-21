#ifndef _BLOCK_HOLDER_H_
#define _BLOCK_HOLDER_H_

#include <vector>
#include <memory>
#include "type.h"
#include "block.h"
#include "difficulty.h"

class Grid;
class BlockHolder {
  
  Block currentBlock, nextBlock;
  int blockCounter = 0;
  
  std::vector<std::shared_ptr<Difficulty>> levels;

  std::weak_ptr<Grid> theGrid;
  
public:
  void setGrid(std::shared_ptr<Grid> g);
  Block &getCurrentBlock();      // return the current block  
  Block &getNextBlock();         // return the type of next block
  void mutate(Move cmd, const int num = 1);   // mutate the current block
  void changeShape(Shape s);                  // change shape of current block
  void switchToNextBlock();     // sets the currentblock to the next block
  bool gameOver();              // return if the game is over
  std::shared_ptr<Difficulty> getDifficulty(); // Returns the difficulty decorator that generates new blocks
  void setLoadPath(std::string path);          // Sets the file path to make random levels not random
  void implementPenalty();                     // Penalty for not clearing boards quick enough
};

#endif
