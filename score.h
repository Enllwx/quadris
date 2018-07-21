#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include "type.h"

class ScoreCounter {
    int maxSoFar = 0;
    int totalScore = 0;
public:
    void clear();           // totalScore back to 0
    void addScore(Level lvl, int lines);  // add score
    void addScore(Level lvl);  // add score
    friend std::ostream &operator<<(std::ostream &out, ScoreCounter &s);
};

#endif /* score_h */
