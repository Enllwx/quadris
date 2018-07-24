#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H

#include <memory>
#include <string>
#include <vector>
#include "window.h"
#include "cell.h"
#include "block.h"
#include "type.h"

class GraphicsDisplay{
    
    int cellSize, leftOffset, topOffset, rightOffset, bottomOffset;
    std::shared_ptr<Xwindow> theDisplay;              // The Xwindow used to display the grid
    std::vector<std::vector <Cell> > * board;
    
    void drawCell(int row, int col, int colour);
    void drawText(int row, int col, std::string txt);
    void drawText(int row, int col, int i);
    
    int getColour(Content c);
    
    
public:
    GraphicsDisplay(int width = 11, int height = 18,
                    int cellSize = 25,
                    int leftOffset = 25, int topOffset = 25,
                    int rightOffset = 200, int bottomOffset = 50);
    void setGrid(std::vector<std::vector<Cell>> * board);
    void showInfo(int lvl, int total, int MaxSofar);
    void showNextBlock(Block b);
    friend std::ostream &operator<<(std::ostream &out, GraphicsDisplay &gd);
};

#endif

