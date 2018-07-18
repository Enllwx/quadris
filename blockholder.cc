#include <vector>
#include <iostream>
#include "blockholder.h"
#include "grid.h"

BlockHolder::BlockHolder(Grid *g):
  theGrid{g}, levelZero{LevelZero()}
{
  levels.emplace_back(&levelZero);

  for(int i=0; i<levels.size(); ++i) levels[i]->setGrid(g);

  currentBlock = getDifficulty(g->getDifficulty())->newBlock();
  nextBlock = getDifficulty(g->getDifficulty())->newBlock();
}

Difficulty* BlockHolder::getDifficulty(Level lvl){
  return levels[lvl];
}

// return the next block
Block& BlockHolder::getNextBlock() { return nextBlock; }

// return the current block
Block& BlockHolder::getCurrentBlock() { return currentBlock; }

// mutate the current block
void BlockHolder::mutate(Move cmd, const int num){
  for(int i=0; i<num; ++i){
    switch(cmd){
      case Move::Left :
        currentBlock = getDifficulty(theGrid->getDifficulty())->moveLeft(currentBlock);
        break;
      case Move::Right :
        currentBlock = getDifficulty(theGrid->getDifficulty())->moveRight(currentBlock);
        break;
      case Move::Down :
        currentBlock =  getDifficulty(theGrid->getDifficulty())->moveDown(currentBlock);
        break;
      case Move::Drop :
        currentBlock = getDifficulty(theGrid->getDifficulty())->drop(currentBlock);
        break;
      case Move::CounterRotate :
        currentBlock = getDifficulty(theGrid->getDifficulty())->rotateCounter(currentBlock);
        break;
      case Move::Rotate :
        currentBlock = getDifficulty(theGrid->getDifficulty())->rotateClock(currentBlock);
        break;
    }
  } theGrid->update();
}

// give hint for current block
void BlockHolder::hint(){

}

void BlockHolder::generateNextBlock(){
  std::cout << "Next block" << std::endl;
  currentBlock = getDifficulty(theGrid->getDifficulty())->newBlock();  
}

bool BlockHolder::gameOver(){
  return false;
}
