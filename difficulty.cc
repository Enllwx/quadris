#include "difficulty.h"
#include "grid.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

Difficulty::Difficulty(std::shared_ptr<Grid> g, std::string loadPath):
  theGrid{g},
  loadPath{loadPath}
{ setLoadPath(loadPath); }
Difficulty::Difficulty(){}

bool Difficulty::validPosition(Block b){
  std::vector<Cell> area = b.getArea();
  
  for(int i=0; i<area.size(); ++i){
    if(area[i].row < 0 || area[i].row >= theGrid.lock()->getHeight() ||
       area[i].col < 0 || area[i].col >= theGrid.lock()->getWidth() ||
       theGrid.lock()->cellOccupied(area[i].row, area[i].col))
      return false;
  } return true;
}

// MAGIC: DO NOT TOUCH!!!
Block Difficulty::cwRotate(Block b){
  int weight = b.getWeight();
  int width = b.getWidth(), height = b.getHeight();
  Block rotated = b;
  
  std::vector<Cell> oldArea = b.getArea();
  std::vector<Cell> newArea;
  for(int i=0; i<oldArea.size(); ++i)
    // Following 3 lines is the key that makes the rotation work!
    // Does magic calculations. Don't think too much about it. Thinking is bad for your brain.
    newArea.emplace_back(Cell{oldArea[i].content,
                              (b.getRow() - width + 1) + (oldArea[i].col - b.getCol()),
                              b.getCol() + (b.getRow() - oldArea[i].row)});

  rotated.setArea(newArea);
  rotated.setRotation((b.getRotation()+1) % 4);

  if(validPosition(rotated)) rotated;
  return b;
}

Block Difficulty::moveByWeight(Block b){
  //std::cout << "weight = " << b.getWeight() << std::endl;
  Block moved = b;
  moved.setRow(b.getRow()+b.getWeight());
  
  if(validPosition(moved)) return moved;
  return b;  
}

Block Difficulty::rotateClock(Block b){
  return moveByWeight(cwRotate(b));
}

Block Difficulty::rotateCounter(Block b){
  return moveByWeight(cwRotate(cwRotate(cwRotate(b))));
}

Block Difficulty::moveDown(Block b){
  Block moved = b;
  moved.setRow(b.getRow()+1);
  
  if(validPosition(moved)) return moveByWeight(moved);
  return moveByWeight(b);
}

Block Difficulty::moveLeft(Block b){
  Block moved = b;
  moved.setCol(b.getCol()-1);

  if(validPosition(moved)) return moveByWeight(moved);
  return moveByWeight(b);
}

Block Difficulty::moveRight(Block b){
  Block moved = b;
  moved.setCol(b.getCol()+1);

  if(validPosition(moved)) return moveByWeight(moved);
  return moveByWeight(b);
}

Block Difficulty::drop(Block b){
  int prevRow = b.getRow();
  Block moved = moveDown(b);
  int currRow = moved.getRow();
  for(int prevRow = b.getRow(), currRow = moved.getRow();
      prevRow != currRow;){
    prevRow = currRow;
    moved = moveDown(moved);
    currRow = moved.getRow();
  }

  return moveByWeight(moved);
}

void Difficulty::setLoadPath(std::string path){
  loadPath = path; counter = 0;
  generationSequence.clear();

  try{
    std::ifstream reader(loadPath);
    char c = '0';
    while(reader >> c){
      Shape s = Shape::Iblock;
      switch(c){
        case Content::I : s = Shape::Iblock; break;
        case Content::J : s = Shape::Jblock; break;
        case Content::O : s = Shape::Oblock; break;
        case Content::L : s = Shape::Lblock; break;
        case Content::S : s = Shape::Sblock; break;
        case Content::Z : s = Shape::Zblock; break;
        case Content::T : s = Shape::Tblock; break;
      } generationSequence.emplace_back(s);
    }
  } catch(std::runtime_error &e){}
}

void Difficulty::setSeed(int s){ srand(s); }

void Difficulty::implementPenalty(){}
