#include "vector"
#include "blockholder.h"

// return the type of next block
Shape BlockHolder::nextBlockType() const { return nextBlock->type; }

// mutate the current block
void BlockHolder::mutate(const int num, Move cmd,
            std::vector <std::vector <Cell*>> board)
{
    
}

// give hint for current block
void BlockHolder::hint(std::vector <std::vector <Cell*>> board)
{
    
}
