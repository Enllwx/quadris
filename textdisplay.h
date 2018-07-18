#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>
#include "type.h"

class Grid;
class TextDisplay {
  Grid *theGrid;
  std::vector<std::vector <char>> board;
 public:
  TextDisplay(Grid *g);

  friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};
#endif /* TextDisplay_h */
