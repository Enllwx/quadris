#ifndef _CELL_H_
#define _CELL_H_

#include "type.h"

struct Cell{
  Content content = Content::Empty;
  int row = 0, col = 0;
  int rotation = -1; // Rotation of the block at cell. Used for hinting purposes
  Level level = Level::lvl0; // Level at which the cell was placed
  int numBlock = -1; // Block id stored at current cell
  bool temperary = false;
};

#endif

