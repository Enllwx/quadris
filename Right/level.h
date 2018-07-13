#ifndef LEVEL_H
#define LEVEL_H

#include "type.h"
#include "difficulty.h"

class levelZero : public Difficulty {
protected:
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelOne : public Difficulty {
protected:
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelTwo : public Difficulty {
protected:
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelThree : public Difficulty {
protected:
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

class levelFour : public Difficulty {
protected:
    Block newBlock() override;
    void moveDown(Block & b) override;
    void moveLeft(Block & b) override;
    void moveRight(Block & b) override;
    void rotateClock(Block & b) override;
    void rotateCounter(Block & b) override;
};

#endif /* level_h */
