#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>
#include <memory>
#include "cell.h"
#include "type.h"

class Grid;
class TextDisplay {

  std::vector<std::vector <Cell>> * board;
 public:
  void setGrid(std::vector<std::vector <Cell>> * board);
  friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};
#endif /* TextDisplay_h */

