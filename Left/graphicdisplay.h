#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <vector>
#include "score.h"
#include "type.h"
#include "window.h"


class GraphicDisplay
{
    Xwindow* window;
    std::vector<std::vector<char*>> board;
public:
    GraphicDisplay(std::vector <std::vector <Cell*>> &board);
    void update(int lineNum = 1);
    void drawGraph(int lvl, Shape NexBlock, scoreCounter* s) const;
    void gameOver(int score) const;
};



#endif /* graphicsdisplay_h */
