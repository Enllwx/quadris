#include "leveltwo.h"

LevelTwo::LevelTwo(std::shared_ptr<Grid> g, std::string path):
  Difficulty{g, path}
{
  generationSequence.emplace_back(Shape::Iblock);
  generationSequence.emplace_back(Shape::Jblock);
  generationSequence.emplace_back(Shape::Oblock);
  generationSequence.emplace_back(Shape::Lblock);
  generationSequence.emplace_back(Shape::Sblock);
  generationSequence.emplace_back(Shape::Zblock);
  generationSequence.emplace_back(Shape::Tblock);
}

Block LevelTwo::newBlock(){
  return Block(generationSequence[rand() % generationSequence.size()], 0, 3, 0, Level::lvl2);
}

void LevelTwo::setLoadPath(std::string path){}
