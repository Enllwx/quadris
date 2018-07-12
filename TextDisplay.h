#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>
#include "type.h"

class TextDisplay: public Observer<Info, State> {
    std::vector<std::vector<char*>> board;
protected:
    // ctor
    TextDisplay(vector <vector <Cell*>> &board);
    // erase the first linNum vectors in board
    void update(int lineNum = 1);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif /* TextDisplay_h */
