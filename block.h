#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cell.h"
#include "type.h"
#include <vector>

class Block{
  std::vector<Cell> area;
  Shape shape;
  int heaviness;
  int row, col;
  
public:  
  Block(Shape s = Shape::Iblock, int heaviness = 0,
        int r = 3, int c = 0);
  int getRow() const;
  int getCol() const;
  int setRow(int r);
  int setCol(int c);
  Shape getShape() const;
  Shape setShape(Shape s);
  int getWeight() const;
  std::vector<Cell> getArea() const;
  void setArea(std::vector<Cell> newArea);
};

#endif
