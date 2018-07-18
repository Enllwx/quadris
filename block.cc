#include "block.h"

Block::Block(Shape s, int heaviness, int r, int c): row{r}, col{c}, shape{s}{
  switch(s){
    case Shape::Iblock :
      area.emplace_back(Cell{Content::I, 3, 0});
      area.emplace_back(Cell{Content::I, 3, 1});
      area.emplace_back(Cell{Content::I, 3, 2});
      area.emplace_back(Cell{Content::I, 3, 3});
      break;
    case Shape::Jblock :
      area.emplace_back(Cell{Content::J, 2, 0});
      area.emplace_back(Cell{Content::J, 3, 0});
      area.emplace_back(Cell{Content::J, 3, 1});
      area.emplace_back(Cell{Content::J, 3, 2});
      break;
    case Shape::Oblock :
      area.emplace_back(Cell{Content::O, 3, 0});
      area.emplace_back(Cell{Content::O, 3, 1});
      area.emplace_back(Cell{Content::O, 2, 1});
      area.emplace_back(Cell{Content::O, 2, 0});
      break;
    case Shape::Lblock :
      area.emplace_back(Cell{Content::L, 2, 2});
      area.emplace_back(Cell{Content::L, 3, 2});
      area.emplace_back(Cell{Content::L, 3, 1});
      area.emplace_back(Cell{Content::L, 3, 0});
      break;
    case Shape::Sblock :
      area.emplace_back(Cell{Content::S, 3, 0});
      area.emplace_back(Cell{Content::S, 3, 1});
      area.emplace_back(Cell{Content::S, 2, 1});
      area.emplace_back(Cell{Content::S, 2, 2});
      break;
    case Shape::Zblock :
      area.emplace_back(Cell{Content::Z, 2, 0});
      area.emplace_back(Cell{Content::Z, 2, 1});
      area.emplace_back(Cell{Content::Z, 3, 1});
      area.emplace_back(Cell{Content::Z, 3, 2});
      break;
    case Shape::Tblock :
      area.emplace_back(Cell{Content::T, 2, 0});
      area.emplace_back(Cell{Content::T, 2, 1});
      area.emplace_back(Cell{Content::T, 2, 2});
      area.emplace_back(Cell{Content::T, 3, 1});
      break;
    }
}

int Block::getRow() const { return row; }
int Block::setRow(int r) { row = r; }

int Block::getCol() const { return col; }
int Block::setCol(int c) { col = c; }

Shape Block::getShape() const { return shape; }
Shape Block::setShape(Shape s) {
  shape = s;  // NO NO NO NO and NO. BAD!!!!
}

int Block::getWeight() const { return heaviness; }
std::vector<Cell> Block::getArea() const { return area; }
void Block::setArea(std::vector<Cell> newArea){ area = newArea; }

int Block::getWidth() const{
  int width = 0;
  for(int i=0; i<area.size(); ++i) width = std::max(width, area[i].col - col);
  return width;
}

int Block::getHeight() const{
  int height = 0;
  for(int i=0; i<area.size(); ++i) height = std::max(height, area[i].row - row);
  return height;
}
