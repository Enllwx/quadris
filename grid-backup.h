#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <iostream>
#include <memory>
#include "type.h"
#include "cell.h"
#include "blockholder.h"
#include "hintgenerator.h"
#include "textdisplay.h"

class Grid : public std::enable_shared_from_this<Grid> {
  int width, height;
  Level difficultyLevel;
  std::vector<std::vector <Cell>> board;
  BlockHolder theHolder;
  TextDisplay td;
  bool showHint = false;
  Block hintBlock;
  std::string defaultLoadPath;
  // GraphicDisplay* gd = nullptr;
  // ScoreCounter* score = nullptr;
  // point to same place as "difficultyLevel" in BlockHolder

  void showCurrentPosition();
  void eliminateRow();
  
public:  
  Grid(int w = 11, int h = 15, Level d = Level::lvl0,
       bool textOnly = true, std::string path = "sequence.txt");
  void init();

  Cell getCell(int row, int col);
  bool cellOccupied(int row, int col);
  int getWidth();
  int getHeight();
  Level getLevel();
  BlockHolder& getBlockHolder();
  
  void update();      // update() the board (may eliminate lines)
  void clear();       // clear() clear the board
  void hint();        // hint() give the best solution of current block
  bool shouldShowHint();
  Block getHint();
  void gameOver();    // gameOver() determine if the game is over
  void changeLevel(Level num);
  void mutate(Move cmd, const int num = 1);
  void changeShape(Shape s);
  std::shared_ptr<Difficulty> getDifficulty();
  void setLoadPath(std::string path);
  std::string getDefaultLoadPath();
  
  friend std::ostream &operator<<(std::ostream &out, Grid &g);
};

#endif /* grid_hpp */
