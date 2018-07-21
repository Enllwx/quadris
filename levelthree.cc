#include "levelthree.h"

LevelThree::LevelThree(std::shared_ptr<Grid> g, std::string path):
  Difficulty{g, path}
{
  generationSequence.emplace_back(Shape::Iblock);
  generationSequence.emplace_back(Shape::Jblock);
  generationSequence.emplace_back(Shape::Oblock);
  generationSequence.emplace_back(Shape::Lblock);
  for(int i=0; i<2; ++i)
    generationSequence.emplace_back(Shape::Sblock);
  for(int i=0; i<2; ++i)
    generationSequence.emplace_back(Shape::Zblock);
  generationSequence.emplace_back(Shape::Tblock);
}

Block LevelThree::newBlock(){
  if(loadPath != ""){
    if(generationSequence.size() != 0){
      counter %= generationSequence.size();
      return Block(generationSequence[counter++], 1, 3, 0, Level::lvl0);
    } else return Block();
  } return Block(generationSequence[rand() % generationSequence.size()], 1, 3, 0, Level::lvl3);
}
