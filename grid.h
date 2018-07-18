#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <iostream>
#include "type.h"
#include "cell.h"
#include "blockholder.h"
#include "textdisplay.h"

class Grid {
  int width, height;
  Level difficultyLevel;
  std::vector<std::vector <Cell>> board;
  BlockHolder theHolder;
  TextDisplay td;
  // GraphicDisplay* gd = nullptr;
  // ScoreCounter* score = nullptr;
  // point to same place as "difficultyLevel" in BlockHolder

  void showCurrentPosition();
  void eliminateRow();
  
public:
  Grid(int w = 11, int h = 15, Level d = Level::lvl0, bool textOnly = true);     // ctor

  Cell getCell(int row, int col);
  bool cellOccupied(int row, int col);
  int getWidth();
  int getHeight();
  Level getDifficulty();
  BlockHolder& getBlockHolder();
  
  void update();      // update() the board (may eliminate lines)
  void clear();       // clear() clear the board
  void hint();        // hint() give the best solution of current block
  void gameOver();    // gameOver() determine if the game is over
  void changeLevel(Level num);
  // mutate() change the current block
  void mutate(Move cmd, const int num = 1);

  friend std::ostream &operator<<(std::ostream &out, Grid &g);
};

#endif /* grid_hpp */
