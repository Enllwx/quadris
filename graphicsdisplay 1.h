#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H

#include <memory>
#include <string>
#include "window.h"
#include "grid.h"
#include "type.h"

class GraphicsDisplay{
  std::shared_ptr<Xwindow> theDisplay;              // The Xwindow used to display the grid
  std::weak_ptr<Grid> theGrid;
  std::vector<std::vector <Cell>> board;
  std::vector <Cell> cleanup;

  int cellSize, leftOffset, topOffset, rightOffset, bottomOffset;
  
  void drawCell(int row, int col, int colour);
  
  void drawText(int row, int col, std::string txt);
  void drawText(int row, int col, int i);

  int getColour(char c);
  
  void showInfo();
  void showNextBlock();
  
 public:
  GraphicsDisplay(int width = 11, int height = 18,
                  int cellSize = 25,
                  int leftOffset = 25, int topOffset = 25,
                  int rightOffset = 200, int bottomOffset = 50);
  void setGrid(std::shared_ptr<Grid> g);
  void update();
};

#endif
