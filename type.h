#ifndef TYPE_H
#define TYPE_H

enum class Level {lvl0, lvl1, lvl2, lvl3, lvl4};
enum class Shape {Iblock, Jblock, Oblock, Lblock,
                    Sblock, Zblock, Tblock};
enum class Move {Left, Right, down, CounterRotate, Rotate};
enum class State {occuped, temp, empty};

// cell is componet of board
struct Cell {
    const int x;
    const int y;
    char type = '-';
    State state = State::empty;  // defualt type: empty
};

struct Block {
    Cell *area[4];
    Shape type = Shape::Iblock;
};

#endif /* type.h */
