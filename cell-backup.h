#ifndef _CELL_H_
#define _CELL_H_

#include "type.h"

struct Cell{
  Content content = Content::Empty;
  int row = 0, col = 0;
  int rotation = -1; // Rotation of the block at cell. Used for hinting purposes
  int numBlock = -1; // Id of the block fixed at cell. Used for scoring purposes
};

#endif
