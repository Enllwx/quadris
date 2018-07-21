#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cell.h"
#include "type.h"
#include <vector>
#include <iostream>

class Block{
  std::vector<Cell> area;
  Shape shape;
  int heaviness;
  int row, col;
  Level levelGenerated;
  int rotation; // Rotation state. Used for recursive backtracking in hinting
  int blockId; // Id of the current block
  
public:  
  Block(Shape s = Shape::Iblock,
        int heaviness = 0,
        int r = 3, int c = 0,
        Level lvl = Level::lvl0);
  int getRow() const;
  int getCol() const;
  int setRow(int r);
  int setCol(int c);
  Shape getShape() const;
  void setShape(Shape s);
  int getWeight() const;
  int getWidth() const;
  int getHeight() const;
  std::vector<Cell> getArea() const;
  void setArea(const std::vector<Cell> &newArea);
  void setRotation(int r);
  int getRotation();

  int getId();
  void setId(int id);

  Level getLevel();
  
  friend std::ostream &operator<<(std::ostream &out, Block &b);
};

#endif
