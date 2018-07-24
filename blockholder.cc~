#include <vector>
#include <iostream>
#include "blockholder.h"
#include "grid.h"

#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"

void BlockHolder::setGrid(std::shared_ptr<Grid> g)
{
  theGrid = g;
  levels.clear();
  
  levels.emplace_back(std::make_shared<LevelZero>(g));
  levels.emplace_back(std::make_shared<LevelOne>(g));
  levels.emplace_back(std::make_shared<LevelTwo>(g));
  levels.emplace_back(std::make_shared<LevelThree>(g));
  levels.emplace_back(std::make_shared<LevelFour>(g));

  levels[Level::lvl0]->setLoadPath(g->getDefaultLoadPath());
  
  currentBlock = getDifficulty()->newBlock();
  currentBlock.setId(blockCounter++);
  nextBlock = getDifficulty()->newBlock();
  nextBlock.setId(blockCounter++);
}

std::shared_ptr<Difficulty> BlockHolder::getDifficulty(){
  return levels[theGrid.lock()->getLevel()];
}

// return the next block
Block &BlockHolder::getNextBlock() { return nextBlock; }

// return the current block
Block &BlockHolder::getCurrentBlock() { return currentBlock; }

// mutate the current block
void BlockHolder::mutate(Move cmd, const int num){
  for(int i=0; i<num; ++i){
    switch(cmd){
      case Move::Left :
        currentBlock = getDifficulty()->moveLeft(currentBlock);
        break;
      case Move::Right :
        currentBlock = getDifficulty()->moveRight(currentBlock);
        break;
      case Move::Down :
        currentBlock =  getDifficulty()->moveDown(currentBlock);
        break;
      case Move::Drop :
        currentBlock = getDifficulty()->drop(currentBlock);
        break;
      case Move::CounterRotate :
        currentBlock = getDifficulty()->rotateCounter(currentBlock);
        break;
      case Move::Rotate :
        currentBlock = getDifficulty()->rotateClock(currentBlock);
        break;
    }
  } theGrid.lock()->update();
}

// change shape of current block
void BlockHolder::changeShape(Shape s){
  Block backUp = currentBlock;
  currentBlock.setShape(s);
  if(!getDifficulty()->validPosition(currentBlock)) currentBlock = backUp;
}

void BlockHolder::switchToNextBlock(){
  currentBlock = nextBlock;
  nextBlock = getDifficulty()->newBlock();
  nextBlock.setId(blockCounter++);
}

bool BlockHolder::gameOver(){
  return false;
}

void BlockHolder::setLoadPath(std::string path){
  for(int i=0; i<levels.size(); ++i) levels[i]->setLoadPath(path);
}

void BlockHolder::implementPenalty(){
  getDifficulty()->implementPenalty();
}
