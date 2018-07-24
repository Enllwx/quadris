#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cell.h"
#include "type.h"
#include <vector>
#include <iostream>

class Block{

    std::vector<Cell> area;
    int heaviness;
    int row, col;
    int rotation; // Rotation state. Used for recursive backtracking in hinting
    int blockId;  // Id of the current block
    Level levelGenerated;
    Shape shape;
    
public:
    
    // ctor
    Block(Shape s = Shape::Iblock,
          int heaviness = 0,
          int r = 3, int c = 0,
          Level lvl = Level::lvl0);
    
    
    // follow methods get the information of the object Block
    int getId() const;
    int getRow() const;
    int getCol() const;
    int getWeight() const;
    int getWidth() const;
    int getHeight() const;
    int getRotation() const;
    Level getLevel() const;
    Shape getShape() const;
    std::vector<Cell> getArea() const;
    
    
    // following methods mutate the fields in block
    void setRow(int r);
    void setCol(int c);
    void setId(int id);
    void setShape(Shape s);
    void setRotation(int r);
    void setArea(const std::vector<Cell> &newArea);
    
    
    // function overload
    friend std::ostream &operator<<(std::ostream &out, Block &b);
};

#endif

