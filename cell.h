#ifndef _CELL_H_
#define _CELL_H_

#include "type.h"

struct Cell{
  Content content = Content::Empty;
  int row = 0, col = 0;
};

#endif
