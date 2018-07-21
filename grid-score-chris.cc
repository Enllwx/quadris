#include "grid.h"
#include <memory.h>
#include <iostream>

Grid::Grid(int w, int h, Level d, bool textOnly):
width{w}, height{h+3}, difficultyLevel{d}{}

void Grid::init(){
  board.clear();
  board.resize(height);
  for(int row = 0; row < height; ++row){
    for(int col = 0; col < width; ++col)
      board[row].emplace_back(Cell{Content::Empty, row, col});
  }
  td.setGrid(shared_from_this());
  theHolder.setGrid(shared_from_this());
  //board[3][0].content = Content::Extra;
  //board[2][2].content = Content::Extra;  
}

Cell Grid::getCell(int row, int col){ return board[row][col]; }
bool Grid::cellOccupied(int row, int col){ return board[row][col].content != Content::Empty; }
int Grid::getWidth(){ return width; }
int Grid::getHeight(){ return height; }
Level Grid::getLevel(){ return difficultyLevel; }
std::shared_ptr<Difficulty> Grid::getDifficulty(){ return theHolder.getDifficulty(); }

BlockHolder& Grid::getBlockHolder(){ return theHolder; }

// Function used to debug. Shows position of current block
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
    ///////////////////// score.addScore(board[row][col].level);
      std::vector <int> eliminateNum;
      std::vector <int> eliminateCheaker;
      std::vector <Level> eliminateLevel;
      eliminateNum.resize(getWidth());
      eliminateCheaker.resize(getWidth());
      eliminateLevel.resize(getWidth());
      // save all possibles in array eliminateNum[]
      int counter = 0;
      for (int col=0; col<getWidth(); col++){
          int non_repeated = 1;
	  for (int i=0; i<col; i++){
	      if (eliminateNum[i] == board[row][col].numBlock)
              { non_repeated = 0; }
	  } 
	  if (non_repeated){ 
	      counter++;
	      eliminateNum[col] = board[row][col].numBlock;
	      eliminateLevel[col] = board[row][col].level;
	  }
      }
    /////////////////////
      
      board.erase(board.begin() + row);              // Delete full row
      std::vector<Cell> newRow;                      // Make new empty row
      newRow.resize(getWidth());
      board.insert(board.begin(), newRow);           // Insert new row
      
    /////////////////////
      for (int i=0; i<getHeight(); i++){
          for (int j=0; j<getWidth(); j++){     // mutate the row and col number
              board[i][j].row = i;
              board[i][j].col = j;
              for (int col=0; col<getWidth(); col++){
                  if (board[i][j].numBlock == eliminateNum[col])
                      eliminateCheaker[col] = 1;      // the block still left
              }
          }
      }
      
      // add score   
      for (int col=0; col<counter; col++){
          if (eliminateCheaker[col] == 0)
              score.addScore(eliminateLevel[col]);
      }// for line
      score.addScore(difficultyLevel, 1);
  }
}

// update() the board (may eliminate lines by calling eliminateRow())
void Grid::update(){
  //std::cout << "Update grid" << std::endl;
  //showCurrentPosition();

  // Checks if need to request next block
  Block currentBlock = theHolder.getCurrentBlock();
  bool requestNext = false;
  if(currentBlock.getRow() == getHeight()-1) requestNext = true;   // Request next block when current block at end of board
  else{                                                            // Or when resting on other blocks
    std::vector<Cell> area = currentBlock.getArea();
    
    for(int i=0; i<area.size(); ++i){
      if(cellOccupied(area[i].row+1, area[i].col)){
        requestNext = true;
        break;
      }
    }
  }

  if(requestNext){
    // Place block into board
    std::vector<Cell> area = currentBlock.getArea();
    for(int i=0; i<area.size(); ++i){
      board[area[i].row][area[i].col].content = area[i].content;
      board[area[i].row][area[i].col].numBlock = currentBlock.getId();
    }
    
    theHolder.switchToNextBlock();  // Request next block
    eliminateRow();         // Eliminate rows if possible
    
  }
  
  //std::cout << "Updated grid" << std::endl;
  //showCurrentPosition();
}

// clear() clear the board
void Grid::clear(){
  //score->clear();
  // theHolder->clear();
  // for (int i=0; i<18; i++){
  //   for (int j=0; j<11; j++){
  board.erase(board.begin() + row);    //     board.back[i][j].type = '-';
  //   }
  // }
}


// hint() give the best solution of current block
void Grid::hint(){
  showHint = true;
  hintBlock = HintGenerator(shared_from_this()).generateHint();
}

bool Grid::shouldShowHint(){ return showHint; }
Block Grid::getHint(){
  showHint = false;
  return hintBlock;
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
void Grid::changeLevel(int num)
{
    switch (num) {
        case 0: difficultyLevel = Level::lvl0; break;
        case 1: difficultyLevel = Level::lvl1; break;
        case 2: difficultyLevel = Level::lvl2; break;
        case 3: difficultyLevel = Level::lvl3; break;
        case 4: difficultyLevel = Level::lvl4; break;
    }
}

// mutate() change the current block
void Grid::mutate(Move cmd, const int num){
  //showCurrentPosition();
  showHint = false;
  theHolder.mutate(cmd, num);
}

void Grid::changeShape(Shape s){
  theHolder.changeShape(s);
  update();
}

std::ostream &operator<<(std::ostream &out, Grid &g){
    out << "Level:    ";
    int lvl_num = 0;
    switch (g.difficultyLevel) {
        case Level::lvl0 : lvl_num = 0; break;
        case Level::lvl1 : lvl_num = 1; break;
        case Level::lvl2 : lvl_num = 2; break;
        case Level::lvl3 : lvl_num = 3; break;
        case Level::lvl4 : lvl_num = 4; break;
    }
    out << lvl_num << std::endl;
    out << g.score;
    return out << g.td << std::endl;
}

std::string Grid::getDefaultLoadPath(){ return defaultLoadPath; }
void Grid::setLoadPath(std::string path){ theHolder.setLoadPath(defaultLoadPath); }
