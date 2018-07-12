#ifndef TYPE_H
#define TYPE_H

enum class Level {lvl0, lvl1, lvl2, lvl3, lvl4};
enum class Shape {Iblock, Jblock, Oblock, Lblock,
                    Sblock, Zblock, Tblock};
enum class Move {Left, Right, down, CounterRotate, Rotate};
enum class State {occuped, temp, empty};

// cell is componet of board
class Cell {
    const int x;
    const int y;
    State state = State::empty;  // defualt type: empty
    Shape type = Shape::Iblock; // default type: Iblock
};

// Block has component of 4 cell, it represent a block
class Block {
    Cell area[4];
    Shape BlockType = Shape::Iblock; // default type: Iblock
}
#endif /* type.h */
