#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "type.h"
#include "grid.h"
#include "score.h"
#include "TextDisplay.h"
#include "graphicdisplay.h"
#include "blockholder.h"

using namespace std;

class Grid {
    int *difficultyLevel;
    vector <vector <Cell*>> board;
    BlockHolder* theHolder = nullptr;
    TextDisplay* td = nullptr;
    GraphicDisplay* gd = nullptr;
    ScoreCounter* score = nullptr;
    int *difficultyLevel = nullptr;
    // point to same place as "difficultyLevel" in BlockHolder
public:
    Grid(int *difficulty, int textOnly);     // ctor
    
    void update();      // update() the board (may eliminate lines)
    void clear();       // clear() clear the board
    void hint();        // hint() give the best solution of current block
    void gameOver();    // gameOver() determine if the game is over
    void changeLevel(int num);
    // mutate() change the current block
    void mutate(int num, Move cmd);
    friend ostream& operator<<(std::ostream &out, const Grid &g);
};

#endif /* grid_hpp */
