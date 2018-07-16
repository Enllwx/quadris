#include "vector"
#include "blockholder.h"

// return the type of next block
Shape BlockHolder::nextBlockType() const { return nextBlock->type; }

// mutate the current block
void BlockHolder::mutate(const int num, Move cmd)
{
    
}

// give hint for current block
void BlockHolder::hint()
{
    
}

void BlockHolder::clear()
{
    delete currentBlock;
    delete nextBlock;
    currentBlock = nullptr;
    nextBlock = nullptr;
}

bool BlockHolder::gameOver()()
{
    
}
