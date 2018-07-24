#include "block.h"

Block::Block(Shape s, int heaviness, int r, int c, Level lvl):
  row{r}, col{c}, shape{s},
  heaviness{heaviness},
  levelGenerated{lvl},
  rotation{0}
{
  switch(s){
    case Shape::Iblock :
      area.emplace_back(Cell{Content::I, r, c});
      area.emplace_back(Cell{Content::I, r, c+1});
      area.emplace_back(Cell{Content::I, r, c+2});
      area.emplace_back(Cell{Content::I, r, c+3});
      break;
    case Shape::Jblock :
      area.emplace_back(Cell{Content::J, r-1, c});
      area.emplace_back(Cell{Content::J, r, c});
      area.emplace_back(Cell{Content::J, r, c+1});
      area.emplace_back(Cell{Content::J, r, c+2});
      break;
    case Shape::Oblock :
      area.emplace_back(Cell{Content::O, r, c});
      area.emplace_back(Cell{Content::O, r, c+1});
      area.emplace_back(Cell{Content::O, r-1, c+1});
      area.emplace_back(Cell{Content::O, r-1, c});
      break;
    case Shape::Lblock :
      area.emplace_back(Cell{Content::L, r-1, c+2});
      area.emplace_back(Cell{Content::L, r, c+2});
      area.emplace_back(Cell{Content::L, r, c+1});
      area.emplace_back(Cell{Content::L, r, c});
      break;
    case Shape::Sblock :
      area.emplace_back(Cell{Content::S, r, c});
      area.emplace_back(Cell{Content::S, r, c+1});
      area.emplace_back(Cell{Content::S, r-1, c+1});
      area.emplace_back(Cell{Content::S, r-1, c+2});
      break;
    case Shape::Zblock :
      area.emplace_back(Cell{Content::Z, r-1, c});
      area.emplace_back(Cell{Content::Z, r-1, c+1});
      area.emplace_back(Cell{Content::Z, r, c+1});
      area.emplace_back(Cell{Content::Z, r, c+2});
      break;
    case Shape::Tblock :
      area.emplace_back(Cell{Content::T, r-1, c});
      area.emplace_back(Cell{Content::T, r-1, c+1});
      area.emplace_back(Cell{Content::T, r-1, c+2});
      area.emplace_back(Cell{Content::T, r, c+1});
      break;
    }
}

int Block::getRow() const { return row; }
int Block::setRow(int r) {
  int offset = r - row;

  // Updates the area
  for(int i = 0; i < area.size(); ++i)
    area[i].row += offset;

  // Updates the row
  row += offset;
}

int Block::getCol() const { return col; }
int Block::setCol(int c) {
  int offset = c - col;
  
  // Updates the area
  for(int i = 0; i < area.size(); ++i)
    area[i].col += offset;
  
  // Updates the column
  col += offset;
}

Shape Block::getShape() const { return shape; }
void Block::setShape(Shape s) {  
  Block other = Block(s, heaviness, row, col);
  setArea(other.getArea());
  shape = s;
}

int Block::getWeight() const { return heaviness; }

std::vector<Cell> Block::getArea() const { return area; }
void Block::setArea(const std::vector<Cell> &newArea){
  // Updates the area
  area = newArea;

  // Updates the row and column
  row = area[0].row; col = area[0].col;
  for(int i = 0; i < area.size(); ++i){
    row = std::max(row, area[i].row);
    col = std::min(col, area[i].col);
  }
}

int Block::getWidth() const{
  int width = 0;
  for(int i=0; i<area.size(); ++i) width = std::max(width, area[i].col - col);
  return width+1;
}

int Block::getHeight() const{
  int height = 0;
  for(int i=0; i<area.size(); ++i) height = std::max(height, row - area[i].row);
  return height+1;
}

// Used for recursive backtracking in hinting
void Block::setRotation(int r){ rotation = r % 4; }
int Block::getRotation(){ return rotation; }

// Outputs the block
std::ostream &operator<<(std::ostream &out, Block &b){
  std::vector<std::vector <char>> disp;
  disp.resize(b.getHeight());
  int width = b.getWidth();
  
  // Fills display array with space
  for(int row = 0; row < disp.size(); ++row)
    for(int col = 0; col < width; ++col)
      disp[row].emplace_back(' ');
  
  // Fills occupeid spaces with the correct character
  for(int i=0; i<b.area.size(); ++i)
    disp[b.row - b.area[i].row][b.area[i].col - b.col] = b.area[i].content;

  // Prints the block
  for(int row = disp.size()-1; row >= 0; --row){
    for(int col = 0; col < disp[row].size(); ++col)
      out << (char) disp[row][col];
    out << std::endl;
  }
  
  return out;
}

int Block::getId(){ return blockId; }
void Block::setId(int id){ blockId = id; }

Level Block::getLevel(){ return levelGenerated; }
