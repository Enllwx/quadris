#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include "score.h"
#include "type.h"

class TextDisplay {
    std::vector<std::vector<char*>> board;
public:
    // ctor
    TextDisplay(std::vector <std::vector <Cell*>> &board);
    // erase the first linNum vectors in board
    void update(int lineNum = 1);
    void printText(int lvl, Shape NexBlock, scoreCounter* s) const;
};
#endif /* TextDisplay_h */
