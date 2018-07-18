#include "difficulty.h"
#include "grid.h"
#include <vector>
#include <iostream>

Difficulty::Difficulty(Grid *g): theGrid{g}{}

void Difficulty::setGrid(Grid *g){ theGrid = g; }

bool Difficulty::validPosition(Block b){
  std::vector<Cell> area = b.getArea();
  
  for(int i=0; i<area.size(); ++i){
    if(area[i].row < 0 || area[i].row >= theGrid->getHeight() ||
       area[i].col < 0 || area[i].col >= theGrid->getWidth() ||
       theGrid->cellOccupied(area[i].row, area[i].col))
      return false;
  } return true;
}

// MAGIC: DO NOT TOUCH!!!
Block Difficulty::rotateClock(Block b){
  int width = b.getWidth(), height = b.getHeight();
  Block rotated(b.getShape());
  std::vector<Cell> oldArea = b.getArea();
  std::vector<Cell> newArea;
  for(int i=0; i<oldArea.size(); ++i)
    // Following 3 lines is the key that makes the rotation work!
    // Does magic calculations. Don't think too much about it. Thinking is bad for your brain.
    newArea.emplace_back(Cell{oldArea[i].content,
                              (b.getRow() - width) + (oldArea[i].col - b.getCol()),
                              (b.getCol() + height) - (oldArea[i].row - b.getRow())});

  rotated.setArea(newArea);
  rotated.setRow(b.getRow());
  rotated.setCol(b.getCol());

  if(validPosition(rotated)) return rotated;
  return b;
}

Block Difficulty::rotateCounter(Block b){
  return rotateClock(rotateClock(rotateClock(b)));
}

Block Difficulty::moveDown(Block b){
  std::cout << "Move down" << std::endl;
  std::vector<Cell> area = b.getArea();
  for(int i = 0; i < area.size(); ++i) area[i].row++;

  Block moved(b.getShape());
  moved.setArea(area);
  moved.setRow(b.getRow()+1);
  moved.setCol(b.getCol());
  
  if(validPosition(moved)) return moved;
  return b;  
}

Block Difficulty::moveLeft(Block b){  
  std::vector<Cell> area = b.getArea();
  for(int i = 0; i < area.size(); ++i) area[i].col--;

  Block moved(b.getShape());
  moved.setArea(area);
  moved.setCol(b.getCol()-1);
  moved.setRow(b.getRow());

  if(validPosition(moved)) return moved;
  return b;  
}

Block Difficulty::moveRight(Block b){  
  std::vector<Cell> area = b.getArea();
  for(int i = 0; i < area.size(); ++i) area[i].col++;

  Block moved(b.getShape());
  moved.setArea(area);
  moved.setCol(b.getCol()+1);
  moved.setRow(b.getRow());

  if(validPosition(moved)) return moved;
  return b;  
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

  return moved;
}
