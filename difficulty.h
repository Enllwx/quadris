#ifndef _DIFFICULTY_H_
#define _DIFFICULTY_H_

#include "type.h"
#include "block.h"

class Grid;
class Difficulty {  
protected:
  Grid *theGrid = nullptr;

  bool validPosition(Block b);
  
public:
  Difficulty(Grid *g = nullptr);
  virtual void setGrid(Grid *g);
  virtual Block newBlock() = 0;
  virtual Block rotateClock(Block b);
  virtual Block rotateCounter(Block b);
  virtual Block moveDown(Block b);
  virtual Block moveLeft(Block b);
  virtual Block moveRight(Block b);
  virtual Block drop(Block b);
};

#endif /* difficulty_h */
