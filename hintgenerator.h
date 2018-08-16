#ifndef _HINT_GENERATOR_H_
#define _HINT_GENERATOR_H_

#include "block.h"
#include "cell.h"
#include "difficulty.h"
#include <vector>
#include <memory>

/* ==-------------------------- Algorithm --------------------------== */
//                                                                     //
//    In this class, AI was used to determine the current best move,   //
//  there are several index that will be counted:                      //
//                                                                     //
//    1. line the hint block will help eliminated.                     //
//                                                                     //
//    2. how many small edge was attached by other blocks or           //
//       boundary of the game board                                    //
//                                                                     //
//    3. if there will be hole under the hint block                    //
//       (a) if there are no hold we add score                         //
//       (b) if there are hole right behand, we decrease the score     //
//       (c) if the hole is not right behand the hint block,           //
//           as the distances between closed hold and the hint block   //
//           increasing, we decrease the score by smaller amount       //
//                                                                     //
/* ==----------------------------------------------------------------== */

// forward declaration avoiding cyclic dependency
class Grid;


class HintGenerator {
    float hintGrade = 0;
    Block hintBlock;
    std::vector <std::vector <std::vector <bool>>> visit;
    std::vector <std::vector <Cell>> board;
    
    Block moveByWeight(Block b);
    Block cwRotate(Block b);
    Block rotateClock(Block b);
    Block rotateCounter(Block b);
    Block moveDown(Block b);
    Block moveLeft(Block b);
    Block moveRight(Block b);
    
    bool visited(Block b) const;         // check the given block has been check or not
    
    bool validPosition(Block newB) const;
                                         // check if current block is at valid position
    
    int lineEliminate(Block b) const;    // return how many lines could current block elimimate
    
    int aboveThehole(Block b) const;     // run only when there is hole under the block,
                                            //    give the position of how many lines between
                                            //    the hold and the block
    
    int touchThefloot(Block b) const;    // determine how many cells touch the end of board
    
    int lineCounter(Block b) const;      // count the total line number of current block
    
    int underEdges(Block b) const;       // determine how many cells of the block has
                                            //    something under it
    float scoreCounter(Block b) const;   // evaluate current score for current hint block
    
    void betterHint(Block b);            // change current hintBlock to better option
public:
    HintGenerator(Block b, std::vector <std::vector <Cell>> board);
    Block getHint();
};

#endif


