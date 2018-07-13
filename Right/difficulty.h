#ifndef difficulty_hpp
#define difficulty_hpp

#include "type.h"

class Difficulty {
protected:
    Block newBlock() = 0;
    void rotateClock(Block & b) = 0;
    void rotateCounter(Block & b) = 0;
    void moveDown(Block & b) = 0;
    void moveLeft(Block & b) = 0;
    void moveRight(Block & b) = 0;
};

#endif /* difficulty_hpp */
