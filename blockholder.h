#ifndef _BLOCK_HOLDER_H_
#define _BLOCK_HOLDER_H_

#include <vector>
#include <memory>
#include "type.h"
#include "block.h"
#include "difficulty.h"

class BlockHolder {
    
  Block currentBlock, nextBlock;
  int blockCounter = 0;
  int unclearedCounter = 0;
  Level *difficultyLevel = nullptr;
    
  // std::vector<std::vector<Cell*>> board;
  std::vector<std::shared_ptr<Difficulty>> levels;
    
 public:
  void init(std::vector <std::vector<Cell>> * board,
            Level *difficultyLevel,
            std::string loadPath = "sequence.txt");
    
  Block &getCurrentBlock();      // return the current block
  Block &getNextBlock();         // return the type of next block
  void mutate(Move cmd, const int num = 1);   // mutate the current block
  void changeShape(Shape s);                  // change shape of current block
  void switchToNextBlock();     // sets the currentblock to the next block
  std::shared_ptr<Difficulty> getDifficulty(); // Returns the difficulty decorator that generates new blocks
  // Sets the file path to make random levels not random
  void setLoadPath(std::string path);
    
  // Penalty for not clearing boards quick enough
  bool implementPenalty(bool rowCleared);
};

#endif

