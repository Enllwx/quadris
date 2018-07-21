#include "hintgenerator.h"
#include "grid.h"
#include "difficulty.h"

#include <iostream>

HintGenerator::HintGenerator(std::shared_ptr<Grid> g):
  theGrid{g}
{
  block = g->getBlockHolder().getCurrentBlock();
  memoisations.resize(g->getWidth() * g->getHeight() * 4 + 1);
}

Cell HintGenerator::getMemoisation(int row, int col, int rotation){
  Cell c = memoisations[(theGrid.lock()->getWidth()*row + col)*4 + rotation];
  return memoisations[(theGrid.lock()->getWidth()*row + col)*4 + rotation];
}

Cell HintGenerator::setMemoisation(int row, int col, int rotation, Cell c){
  //std::cout << "memoi" << std::endl;;
  return memoisations[(theGrid.lock()->getWidth()*row + col)*4 + rotation] = c;
}

bool HintGenerator::isMemoised(int row, int col, int rotation){
  return memoisations[(theGrid.lock()->getWidth()*row + col)*4 + rotation].content != Content::Empty;
}

// Returns the score of how good a hint a cell is
int HintGenerator::score(Cell c){
  Block b = block;
  while(b.getRotation() != c.rotation)
    b = theGrid.lock()->getDifficulty()->rotateClock(b);
  
  return c.row - b.getHeight();
}

// Generates the hint
Block HintGenerator::generateHint(){
  Cell c = generateHint(block); // Get where the hint is
  Block b = Block(block.getShape()); 
  while(b.getRotation() != c.rotation) // Set hint block rotation
    b = theGrid.lock()->getDifficulty()->rotateClock(b);
  b.setRow(c.row); b.setCol(c.col); // Set hint block location
  
  return b;
}

//void HintGenerator::output(){
  //for(int row = 0; row < g.lock().get
  //}

// Returns cell, containing the best place to place the given Block b
// Best place is defined as the row which is nearest the bottom that the Block b can get to
Cell HintGenerator::generateHint(Block b, int depth){
  //std::cout << depth << std::endl;
  // if(depth >= MAX_DEPTH)
  //   return setMemoisation(b.getRow(), b.getCol(), b.getRotation(),
  //                         Cell{Content::Hint, b.getRow(), b.getCol(), b.getRotation()});
  
  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << b.getRow() << ", " << b.getCol() << ", " << b.getRotation() << std::endl;
  
  // If current spot with current rotation visited...
  if(isMemoised(b.getRow(), b.getCol(), b.getRotation())){
    // for(int i=0; i<depth; ++i) std::cout << "  ";
    // std::cout << "mem" << std::endl;
    return getMemoisation(b.getRow(), b.getCol(), b.getRotation());
  }

  // If cannot move
  if(b.getRow() >= theGrid.lock()->getHeight()-1){
    //std::cout << "Bottom reached " << std::endl;
    return setMemoisation(b.getRow(), b.getCol(), b.getRotation(),
                          Cell{Content::Hint, b.getRow(), b.getCol(), b.getRotation()});
  }
  std::vector<Cell> area = b.getArea();    
  for(int i=0; i<area.size(); ++i){
    //for(int i=0; i<depth; ++i) std::cout << "  ";
    //std::cout << area[i].row << ", " << area[i].col << std::endl;
    if(theGrid.lock()->cellOccupied(area[i].row+1, area[i].col)){
      //for(int i=0; i<depth; ++i) std::cout << "  ";
      //std::cout << "Stuck ";
      //std::cout << area[i].row << ", " << area[i].col << std::endl;
      return setMemoisation(b.getRow(), b.getCol(), b.getRotation(),
                            Cell{Content::Hint, b.getRow(), b.getCol(), b.getRotation()});
    }
  }

  // Mark current as visited
  Cell best = setMemoisation(b.getRow(), b.getCol(), b.getRotation(),
                             Cell{Content::Hint, b.getRow(), b.getCol(), b.getRotation()});
  
  // If can move, try each move
  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "down" << std::endl;
  Cell potential = generateHint(theGrid.lock()->getDifficulty()->moveDown(b), depth+1);
  if(score(potential) > score(best)) best = potential;

  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "left" << std::endl;
  potential = generateHint(theGrid.lock()->getDifficulty()->moveLeft(b), depth+1);
  if(score(potential) > score(best)) best = potential;

  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "right" << std::endl;
  potential = generateHint(theGrid.lock()->getDifficulty()->moveRight(b), depth+1);
  if(score(potential) > score(best)) best = potential;

  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "cw" << std::endl;
  potential = generateHint(theGrid.lock()->getDifficulty()->rotateClock(b), depth+1);
  if(score(potential) > score(best)) best = potential;

  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "ccw" << std::endl;
  potential = generateHint(theGrid.lock()->getDifficulty()->rotateCounter(b), depth+1);
  if(score(potential) > score(best)) best = potential;

  // for(int i=0; i<depth; ++i) std::cout << "  ";
  // std::cout << "done" << std::endl;
  // Memoise and continue
  return setMemoisation(b.getRow(), b.getCol(), b.getRotation(), best);  
}
