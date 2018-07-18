#include "grid.h"

#include <iostream>
// ctor
/*
  int difficultyLevel;
  vector <vector <Cell*>> board;
  BlockHolder* theHolder;
  TextDisplay* td;
  GraphicDisplay* gd;
  ScoreCounter* score;
  int *difficultyLevel;
*/

Grid::Grid(int w, int h, Level d, bool textOnly):
  width{w}, height{h+3}, difficultyLevel{d},
  theHolder{BlockHolder(this)},
  td{TextDisplay(this)}
{
  board.resize(height);
  for(int row = 0; row < height; ++row){
    for(int col = 0; col < width; ++col)
      board[row].emplace_back(Cell{Content::Empty, row, col});
  }

  //board[6][0].content = Content::Extra;
  //if (textOnly) gd = new GraphicDisplay{board};
  //score = new scoreCounter;
}

Cell Grid::getCell(int row, int col){ return board[row][col]; }
bool Grid::cellOccupied(int row, int col){ return board[row][col].content != Content::Empty; }
int Grid::getWidth(){ return width; }
int Grid::getHeight(){ return height; }
Level Grid::getDifficulty(){ return difficultyLevel; }

BlockHolder& Grid::getBlockHolder(){ return theHolder; }

void Grid::showCurrentPosition(){
  Block b = theHolder.getCurrentBlock();
  std::cout << "Current = (" << b.getRow() << ", " << b.getCol() << ")" << std::endl;
}

// tries to eliminate any rows
void Grid::eliminateRow(){
  for(int row = 0; row < getHeight(); ++row){       // For each row... (go from top of grid (0) to down)
    int occupied = 0;                               // Count occupied cells
    for(int col = 0; col < getWidth(); ++col)
      if(cellOccupied(row, col)) ++occupied;

    if(occupied < getWidth()) continue;            // If row is full...
    board.erase(board.begin() + row);              // Delete full row
    std::vector<Cell> newRow;                      // Make new empty row
    newRow.resize(getWidth());
    board.insert(board.begin(), newRow);           // Insert new row
  }
}

// update() the board (may eliminate lines by calling eliminateRow())
void Grid::update(){
  std::cout << "Update grid" << std::endl;
  showCurrentPosition();

  // Checks if need to request next block
  Block currentBlock = theHolder.getCurrentBlock();
  bool requestNext = false;
  if(currentBlock.getRow() == getHeight()-1) requestNext = true;   // Request next block when current block at end of board
  else{                                                            // Or when resting on other blocks
    for(int d = 0; d < currentBlock.getWidth(); ++d)
      if(cellOccupied(currentBlock.getRow()+1, currentBlock.getCol()+d)){
        requestNext = true;
        break;
      }
  }

  if(requestNext){
    // Place block into board
    std::vector<Cell> area = currentBlock.getArea();
    for(int i=0; i<area.size(); ++i)
      board[area[i].row][area[i].col].content = area[i].content;
    
    theHolder.generateNextBlock();  // Request next block
    eliminateRow();         // Eliminate rows if possible
  }
  std::cout << "Updated grid" << std::endl;
  showCurrentPosition();
}

// clear() clear the board
void Grid::clear(){
  // score->clear();
  // theHolder->clear();
  // for (int i=0; i<18; i++){
  //   for (int j=0; j<11; j++){
  //     board.back[i][j].type = '-';
  //   }
  // }
}


// hint() give the best solution of current block
void Grid::hint() {
  //theHolder->hint();
}

// gameOver() determine if the game is over
void Grid::gameOver(){
  // if ( theHolder->gameOver() ){
  //   cout << "GAME OVER !!!" << endl;
  //   cout << "Your score is " << score->getTotal() << endl;
  //   if (gd) gd->gameOver(score->getTotal());
  // }
    
}

// changeLevel() change the difficult lvl
void Grid::changeLevel(Level num) { difficultyLevel = num; }

// mutate() change the current block
void Grid::mutate(Move cmd, const int num){
  showCurrentPosition();
  theHolder.mutate(cmd, num);
}

std::ostream &operator<<(std::ostream &out, Grid &g){
  return out << g.td;
}
