#include <iostream>
#include "grid.h"
#include "type.h"
#include "textdisplay.h"

void TextDisplay::setGrid(std::shared_ptr<Grid> g){
  theGrid = g;
  board.resize(g->getHeight());

  // Syncs the array of chars with that of the grid
  for(int row = 0; row < theGrid.lock()->getHeight(); ++row)
    for(int col = 0; col < theGrid.lock()->getWidth(); ++col)
      board[row].emplace_back(' ');
}

std::ostream &operator<<(std::ostream &out, TextDisplay &td){
  // Syncs the array of chars with that of the grid
  auto theGrid = td.theGrid.lock();
  for(int row = 0; row < theGrid->getHeight(); ++row)
    for(int col = 0; col < theGrid->getWidth(); ++col)
      td.board[row][col] = theGrid->getCell(row, col).content;

  // Syncs position of current block
  std::vector<Cell> currentArea = theGrid->getBlockHolder().getCurrentBlock().getArea();
  for(int i=0; i<currentArea.size(); ++i)
    td.board[currentArea[i].row][currentArea[i].col] = currentArea[i].content;

  // Displays hint if necessary
  if(theGrid->shouldShowHint()){
    std::vector<Cell> hintArea = theGrid->getHint().getArea();
    for(int i=0; i<hintArea.size(); ++i)
      td.board[hintArea[i].row][hintArea[i].col] = '?';
  }

  // Prints the index
  out << "  ";
  for(int col = 0; col < theGrid->getWidth(); ++col)
    out << col % 10;
  out<< std::endl;
  
  // Prints the seperators
  out << "  ";
  for(int col = 0; col < theGrid->getWidth(); ++col)
    out << '-';
  out<< std::endl;
  
  // Prints the board
  for(int row = 0; row < td.board.size(); ++row){
    out << row % 10 << ' ';
    for(int col = 0; col < td.board[row].size(); ++col)
      out << td.board[row][col];
    out << std::endl;
  }

  // Prints the seperators
  out << "  ";
  for(int col = 0; col < theGrid->getWidth(); ++col)
    out << '-';
  out << std::endl;

  // Prints the index
  out << "  ";
  for(int col = 0; col < theGrid->getWidth(); ++col)
    out << col % 10;
  out<< std::endl;
  
  // Prints the next block
  out << "Next:" << std::endl;
  out << theGrid->getBlockHolder().getNextBlock();
  
  return out;
}
