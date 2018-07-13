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
    void update(int lineNum = 1);
    GraphicDisplay(std::vector <std::vector <Cell*>> &board);
    void drawGraph(int lvl, Shape NexBlock, scoreCounter* s) const;
};



#endif /* graphicsdisplay_h */
