#include "graphicsdisplay.h"
#include "window.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// Creates a GrpahicsDisplay for an n by n grid
GraphicsDisplay::GraphicsDisplay(int width, int height,
                                 int cellSize,
                                 int leftOffset, int topOffset,
                                 int rightOffset, int bottomOffset):
cellSize{cellSize},
leftOffset{leftOffset}, topOffset{topOffset},
rightOffset{rightOffset}, bottomOffset{bottomOffset},
theDisplay{new Xwindow(leftOffset + width * cellSize + rightOffset,
                       topOffset + height * cellSize + bottomOffset)}{}


void GraphicsDisplay::setGrid(vector<vector<Cell>> * board){
    this->board = board;
}

// Draws a cell at the given row at column with specified colour
void GraphicsDisplay::drawCell(int row, int col, int colour){
    //std::cout << row << ", " << col << ", " << colour << std::endl;
    theDisplay->fillRectangle(col * cellSize + leftOffset,
                              row * cellSize + topOffset,
                              cellSize, cellSize, colour);
}

void GraphicsDisplay::drawText(int row, int col, std::string txt){
    theDisplay->fillRectangle(leftOffset + (WIDTH + col + 1)*cellSize,
                              topOffset + cellSize * row,
                              cellSize*3, cellSize, Xwindow::White);
    theDisplay->drawString(leftOffset + (WIDTH + col + 1)*cellSize,
                           topOffset + cellSize * (row + 1), txt);
}

void GraphicsDisplay::drawText(int row, int col, int i){
    std::stringstream ss; ss << i;
    drawText(row, col, ss.str());
}

// Shows score info
void GraphicsDisplay::showInfo(int lvl, int total, int MaxSofar){
    drawText(0, 0, "Level:      " + to_string(lvl));
    drawText(1, 0, "Score:      " + to_string(total));
    drawText(2, 0, "High Score: " + to_string(MaxSofar));
}

// Shows score info
void GraphicsDisplay::showNextBlock(Block b){
    
    int promptRow = std::min((HEIGHT - 1) - b.getHeight() - 2,
                             HEIGHT - 1 - 4);
    
    theDisplay->fillRectangle((WIDTH+1) * cellSize + leftOffset,
                              (promptRow-1) * cellSize + topOffset,
                              cellSize*10, cellSize*10, 0);
    
    drawText(promptRow, 0, "Next:");
    for(auto c : b.getArea()){
        int row = (c.row - b.getRow()) + (HEIGHT - 2);
        int col = WIDTH + 2 + c.col;
        drawCell(row, col, getColour(c.content));
    }
}

int GraphicsDisplay::getColour(Content c){
    switch(c){
        case Content::Hint : return Xwindow::Pink;
        case Content::Empty : return Xwindow::Grey;
        case Content::Extra : return Xwindow::Brown;
        case Content::I : return Xwindow::Red;
        case Content::J : return Xwindow::Green;
        case Content::O : return Xwindow::Blue;
        case Content::L : return Xwindow::Yellow;
        case Content::S : return Xwindow::Purple;
        case Content::Z : return Xwindow::Orange;
        case Content::T : return Xwindow::Black;
    } return Xwindow::White;
}

ostream &operator<<(std::ostream &out, GraphicsDisplay &gd){
    for (int row=0; row<HEIGHT; row++){
        for (int col=0; col<WIDTH; col++){
            int color = getColour(  (*(gd.board))[row][col].content );
            gd.drawCell(row, col, color);
        }
    }
}

