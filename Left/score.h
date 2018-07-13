#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include "type.h"

class scoreCounter {
    int maxSoFar = 0;
    int totalScore = 0;
protected:
    void clear();           // totalScore back to 0
    void addScore(int lvl, int lines);  // add score
public:
    int getTotal() const;   // return totalScore
    int getMax() const;     // return totalScore
};

#endif /* score_h */
