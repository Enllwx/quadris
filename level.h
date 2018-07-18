#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "type.h"
#include "difficulty.h"

class levelZero : public Difficulty {
    std::vector <std::vector <Cell*>> board;
protected:
    levelZero(std::vector <std::vector <Cell*>>& board);
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelOne : public Difficulty {
    std::vector <std::vector <Cell*>> board;
protected:
    levelOne(std::vector <std::vector <Cell*>>& board);
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelTwo : public Difficulty {
    std::vector <std::vector <Cell*>> board;
protected:
    levelTwo(std::vector <std::vector <Cell*>>& board);
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelThree : public Difficulty {
    std::vector <std::vector <Cell*>> board;
protected:
    levelThree(std::vector <std::vector <Cell*>>& board);
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelFour : public Difficulty {
    std::vector <std::vector <Cell*>> board;
protected:
    levelFour(std::vector <std::vector <Cell*>>& board);
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

#endif /* level_h */
