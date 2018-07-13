//
//  grid.hpp
//  object
//
//  Created by Enllwx on 2018-07-12.
//  Copyright © 2018 Enllwx. All rights reserved.
//

#ifndef GRID.H
#define GRID.H

#include "type.h"
#include "grid.h"
#include <vector>
using namespace std;

class Grid {
    int difficultyLevel;
    vector <vector <Cell*>> board;
    BlockHolder* theHolder;
    TextDisplay* td;
    GraphicDisplay* gd;
    ScoreCounter* score;
    int *difficultyLevel;
    // point to same place as "difficultyLevel" in BlockHolder
public:
    Grid();         // ctor
    ~Grid();        // dtor
    
    void update();      // update() the board (may eliminate lines)
    void clear();       // clear() clear the board
    void hint();        // hint() give the best solution of current block
    void gameOver();    // gameOver() determine if the game is over
    void changeLevel(int num);
    // mutate() change the current block
    void mutate(int num, Move cmd,
                vector <vector <Cell*>> board);
    friend operator<<(std::ostream &out, const Grid &g);
}

#endif /* grid_hpp */
