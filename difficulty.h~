#ifndef _DIFFICULTY_H_
#define _DIFFICULTY_H_

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "type.h"
#include "block.h"

class Grid;
class Difficulty {  
protected:
  std::weak_ptr<Grid> theGrid;

  // Sequence of shapes used to generate blocks
  std::vector <Shape> generationSequence;
  int counter = 0;
  std::string loadPath;

  // Moves the given block down depending on the weight
  virtual Block moveByWeight(Block b);

  // Clockwise rotate. No downwards pull by weight
  virtual Block cwRotate(Block b);
  
public:
  Difficulty();
  Difficulty(std::shared_ptr<Grid> g, std::string loadPath = "sequence.txt");
  
  virtual Block newBlock() = 0;
  virtual Block rotateClock(Block b);
  virtual Block rotateCounter(Block b);
  virtual Block moveDown(Block b);
  virtual Block moveLeft(Block b);
  virtual Block moveRight(Block b);
  virtual Block drop(Block b);

  // Checks if given block position is valid
  virtual bool validPosition(Block b);

  // Loads from the file used to randomly generate blocks
  virtual void setLoadPath(std::string path);

  // Sets the seed of random generation
  virtual void setSeed(int s);

  // Penalty for not clearing rows quick enough
  virtual void implementPenalty();
};

#endif /* difficulty_h */
