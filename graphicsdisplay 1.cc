#include "graphicsdisplay.h"
#include "window.h"
#include "type.h"
#include <iostream>
#include <sstream>

// Creates a GrpahicsDisplay for an n by n grid
GraphicsDisplay::GraphicsDisplay(int width, int height,
                                 int cellSize,
                                 int leftOffset, int topOffset,
                                 int rightOffset, int bottomOffset):
  cellSize{cellSize},
  leftOffset{leftOffset}, topOffset{topOffset},
  rightOffset{rightOffset}, bottomOffset{bottomOffset},
  theDisplay{new Xwindow(leftOffset + width * cellSize + rightOffset,
                         topOffset + height * cellSize + bottomOffset)}
{}

void GraphicsDisplay::setGrid(std::shared_ptr<Grid> g){
  theGrid = g;
  board.resize(g->getHeight());

  // Syncs the array of chars with that of the grid
  for(int row = 0; row < theGrid.lock()->getHeight(); ++row)
    for(int col = 0; col < theGrid.lock()->getWidth(); ++col)
      board[row].emplace_back(theGrid.lock()->getCell(row, col));

  theDisplay->fillRectangle(leftOffset, topOffset,
                            cellSize*theGrid.lock()->getWidth(),
                            cellSize*theGrid.lock()->getHeight(),
                            Xwindow::Grey);
  update();
}

// Draws a cell at the given row at column with specified colour
void GraphicsDisplay::drawCell(int row, int col, int colour){
  //std::cout << row << ", " << col << ", " << colour << std::endl;
  theDisplay->fillRectangle(col * cellSize + leftOffset,
                            row * cellSize + topOffset,
                            cellSize, cellSize, colour);
}

void GraphicsDisplay::drawText(int row, int col, std::string txt){
  theDisplay->fillRectangle(leftOffset + (theGrid.lock()->getWidth() + col + 1)*cellSize,
                            topOffset + cellSize * row,
                            cellSize*3, cellSize, Xwindow::White);
  theDisplay->drawString(leftOffset + (theGrid.lock()->getWidth() + col + 1)*cellSize,
                         topOffset + cellSize * (row + 1), txt);
}

void GraphicsDisplay::drawText(int row, int col, int i){
  std::stringstream ss; ss << i;
  drawText(row, col, ss.str());
}

// Shows score info
void GraphicsDisplay::showInfo(){
  drawText(0, 0, "Level:");
  drawText(1, 0, "Score:");
  drawText(2, 0, "High Score:");

  drawText(0, 4, (int) theGrid.lock()->getLevel());
  drawText(1, 4, (int) theGrid.lock()->getScore());
  drawText(2, 4, (int) theGrid.lock()->getHighScore());
}

// Shows score info
void GraphicsDisplay::showNextBlock(){
  Block b = theGrid.lock()->getBlockHolder().getNextBlock();

  int promptRow = std::min((theGrid.lock()->getHeight() - 1) - b.getHeight() - 2,
                           theGrid.lock()->getHeight() - 1 - 4);

  theDisplay->fillRectangle((theGrid.lock()->getWidth()+1) * cellSize + leftOffset,
                            (promptRow-1) * cellSize + topOffset,
                            cellSize*10, cellSize*10, 0);
  
  drawText(promptRow, 0, "Next:");
  for(auto c : b.getArea()){
    int row = (c.row - b.getRow()) + (theGrid.lock()->getHeight() - 2);
    int col = theGrid.lock()->getWidth() + 2 + c.col;
    drawCell(row, col, getColour(c.content));
  }
}

int GraphicsDisplay::getColour(char c){
  switch(c){
    case '?' : return Xwindow::Pink;
    case ' ' : return Xwindow::Grey;
    case '*' : return Xwindow::Brown;
    case 'I' : return Xwindow::Red;
    case 'J' : return Xwindow::Green;
    case 'O' : return Xwindow::Blue;
    case 'L' : return Xwindow::Yellow;
    case 'S' : return Xwindow::Purple;
    case 'Z' : return Xwindow::Orange;
    case 'T' : return Xwindow::Black;
  } return Xwindow::White;
}

void GraphicsDisplay::update(){
  showInfo(); // Shows score info

  // Current board
  // std::vector<std::vector<char>> board;
  // board.resize(theGrid.lock()->getHeight());

  // // Shows hint if necessary
  // if(theGrid.lock()->shouldShowHint()){
  //   std::vector<Cell> hintArea = theGrid.lock()->getHint().getArea();
  //   for(int i=0; i<hintArea.size(); ++i)
  //     board[hintArea[i].row][hintArea[i].col] = '?';
  // }

  for(int row = 0; row < board.size(); ++row)
    for(int col = 0; col < board[row].size(); ++col)
      if(theGrid.lock()->board[row][col].content != this->board[row][col].content)
        drawCell(row+3, col, getColour(theGrid.lock()->board[row][col].content));

  board = theGrid.lock()->board;

  for(auto c: cleanup)
    drawCell(c.row, c.col, Xwindow::Grey);
  
  std::vector<Cell> currentArea = theGrid.lock()->getBlockHolder().getCurrentBlock().getArea();
  cleanup.clear();
  // Shows current block
  for(int i=0; i<currentArea.size(); ++i){
    drawCell(currentArea[i].row, currentArea[i].col,
             getColour(currentArea[i].content));
    cleanup.emplace_back(currentArea[i]);
  }
  
  showNextBlock(); // Shows next block
  
  this->board = board;
}
