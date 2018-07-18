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

  board[5][0].content = Content::Extra;
  //theHolder = new BlockHolder{board};
  //td = new TextDisplay{board};
  //if (textOnly) gd = new GraphicDisplay{board};
  //score = new scoreCounter;
  //difficultyLevel = difficulty;
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

// update() the board (may eliminate lines)
void Grid::update(){
  std::cout << "Update grid" << std::endl;
  showCurrentPosition();
  // int eliminateNum = 0;
  // bool checkEliminate = 1;
    
  // while (checkEliminate){
  //   for (int i=0; i<11; i++){
  //     if (board[17][i]->type == ' '){
  //       checkEliminate = 0;
  //       break;
  //     }
  //   }
        
  //   if (checkEliminate){
  //     board.pop_back();
  //     vector <Cell*> temp;
  //     for (int i=0; i<11; i++) temp.push_back(new Cell{0,i,' '});
  //     board.insert(board.begin(), temp);
  //   }
  // }
    
  // if (eliminateNum){
  //   td->update(eliminateNum);
  //   if (gd) gd->update(eliminateNum);
  //   score->addScore(*difficultyLevel ,eliminateNum);
  // }
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
