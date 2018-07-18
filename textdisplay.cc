#include <iostream>
#include "grid.h"
#include "type.h"
#include "textdisplay.h"

TextDisplay::TextDisplay(Grid *g): theGrid{g}{
  board.resize(g->getHeight());

  // Syncs the array of chars with that of the grid
  for(int row = 0; row < theGrid->getHeight(); ++row)
    for(int col = 0; col < theGrid->getWidth(); ++col)
      board[row].emplace_back(' ');
}

std::ostream &operator<<(std::ostream &out, TextDisplay &td){
  // Syncs the array of chars with that of the grid
  for(int row = 0; row < td.theGrid->getHeight(); ++row)
    for(int col = 0; col < td.theGrid->getWidth(); ++col)
      td.board[row][col] = td.theGrid->getCell(row, col).content;

  // Syncs position of current block
  std::vector<Cell> currentArea = td.theGrid->getBlockHolder().getCurrentBlock().getArea();
  for(int i=0; i<currentArea.size(); ++i)
    td.board[currentArea[i].row][currentArea[i].col] = currentArea[i].content;  
  
  // Prints the seperators
  for(int col = 0; col < td.theGrid->getWidth(); ++col)
    out << '-';
  out<< std::endl;

  // Prints the board
  for(int row = 0; row < td.board.size(); ++row){
    for(int col = 0; col < td.board[row].size(); ++col)
      out << td.board[row][col];
    out << std::endl;
  }

  // Prints the seperators
  for(int col = 0; col < td.theGrid->getWidth(); ++col)
    out << '-';
  out << std::endl;
  
  return out;
}
