#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "type.h"

class BlockHolder {
    Block *nextBlock;
    Block *currentBlock;
    Difficulty level[5];
    int *difficultyLevel = 0;
    std::vector <std::vector <Cell*>> board;
    
public:
    BlockHolder(int *difficulty,
                std::vector <std::vector <Cell*>> board);
    Shape nextBlockType() const;            // return the type of next block
    void mutate(const int num, Move cmd);   // mutate the current block
    void hint();                            // give hint for current block
    void clear();
    bool gameOver();                        // return if the game is over
};

#endif /* block_h */
