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
    int difficultyLevel;
public:
    
}

#endif /* grid_hpp */
