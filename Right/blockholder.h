#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "type.h"

class BlockHolder {
    Block *nextBlock;
    Block *currentBlock;
    Difficulty level[5];
    int *difficultyLevel = 0;
protected:
    Shape nextBlockType() const;            // return the type of next block
    void mutate(const int num, Move cmd,    // mutate the current block
                std::vector <std::vector <Cell*>> board);
                                            // give hint for current block
    void hint(std::vector <std::vector <Cell*>> board);
};

#endif /* block_h */
