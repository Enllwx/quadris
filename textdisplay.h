#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>
#include <memory>
#include "type.h"

class Grid;
class TextDisplay {
  std::weak_ptr<Grid> theGrid;
  std::vector<std::vector <char>> board;
 public:
  void setGrid(std::shared_ptr<Grid> g);

  friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};
#endif /* TextDisplay_h */
