#ifndef _TYPE_H_
#define _TYPE_H_

// Difficulty level
enum Level {lvl0 = 0, lvl1 = 1, lvl2 = 2, lvl3 = 3, lvl4 = 4, maxLvl = 4};

// Shape of block.
enum Shape {Iblock = 0, Jblock = 1, Oblock = 2, Lblock = 3,
            Sblock = 4, Zblock = 5, Tblock = 6};

// What is in each cell
enum Content {Hint = '?', Empty = ' ', Extra = '*',
              I = 'I', J = 'J', O = 'O', L = 'L', S = 'S',
              Z = 'Z', T = 'T'};

enum Move {Left, Right, Down, Drop, CounterRotate, Rotate};

#endif /* type.h */
