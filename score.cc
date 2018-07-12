//
//  score.cpp
//  object
//
//  Created by Enllwx on 2018-07-12.
//  Copyright © 2018 Enllwx. All rights reserved.
//

#include "score.h"

// return the mas scare so far
int scoreCounter::getTotal() const{ return totalScore; }

// return the total score
int scoreCounter::getMax() const{ return maxSoFar; }

// add the new score
void scoreCounter::clear() { totalScore = 0; }

//
void scoreCounter::addScore(int lvl, int lines)
{
    totalScore += (lvl + lines) * (lvl + lines);
    if ( maxSoFar < totalScore ) maxSoFar = totalScore;
}
