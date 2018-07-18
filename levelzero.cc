#include "levelzero.h"

LevelZero::LevelZero(Grid *g): Difficulty{g}{}

Block LevelZero::newBlock(){ return Block(Shape::Sblock, 0, 3, 0); }
