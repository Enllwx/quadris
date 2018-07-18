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

Block Difficulty::rotateClock(Block b){
  bool occupied[4][4];
  bool newOccupied[4][4];
  for(int r=0; r<4; ++r)
    for(int c=0; c<4; ++c)
      newOccupied[r][c] = occupied[r][c] = false;
  
  std::vector<Cell> area = b.getArea();
  for(int i=0; i<area.size(); ++i)
    occupied[b.getRow()-area[i].row][area[i].col-b.getCol()] = true;

  for(int row = 0; row < 4; ++row){
    for(int col = 0; col < 4; ++col)
      std::cout << occupied[row][col];
    std::cout << std::endl;
  }
  
  for(int oldRow = 0, newCol = 0;
      oldRow < 4;
      oldRow++, newCol++){
    for(int oldCol = 0, newRow = 3;
        oldCol < 4;
        oldCol++, newRow--){
      newOccupied[newRow][newCol] = occupied[oldRow][oldCol];
    }
  }

  std::cout << std::endl;
  
  for(int row = 0; row < 4; ++row){
    for(int col = 0; col < 4; ++col)
      std::cout << newOccupied[row][col];
    std::cout << std::endl;
  }

  Block rotated(b.getShape());
  std::vector<Cell> newArea;
  for(int row = 0; row < 4; ++row)
    for(int col = 0; col < 4; ++col)
      if(newOccupied[row][col])
        newArea.emplace_back(Cell{area[0].content, b.getRow() - row, b.getCol() + col});
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
  moved.setRow(b.getCol()-1);
  moved.setCol(b.getRow());

  if(validPosition(moved)) return moved;
  return b;  
}

Block Difficulty::moveRight(Block b){  
  std::vector<Cell> area = b.getArea();
  for(int i = 0; i < area.size(); ++i) area[i].col++;

  Block moved(b.getShape());
  moved.setArea(area);
  moved.setRow(b.getCol()+1);
  moved.setCol(b.getRow());

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
