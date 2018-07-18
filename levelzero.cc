#include "levelzero.h"

LevelZero::LevelZero(Grid *g): Difficulty{g}{}

Block LevelZero::newBlock(){
  counter %= 6;
  //counter++; counter %= 6;
  //counter++;
  //if(counter == 7)  return Block(Shape::Iblock, 0, 3, 0);
  //return Block(Shape::Jblock, 0, 3, 0);
  return Block((Shape) (counter++), 0, 3, 0);
}
