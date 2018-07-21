#include "levelfour.h"
#include "grid.h"

LevelFour::LevelFour(std::shared_ptr<Grid> g, std::string path):
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

Block LevelFour::newBlock(){
  if(loadPath != ""){
    if(generationSequence.size() != 0){
      counter %= generationSequence.size();
      return Block(generationSequence[counter++], 1, 3, 0, Level::lvl0);
    } else return Block();
  } return Block(generationSequence[rand() % generationSequence.size()], 1, 3, 0, Level::lvl4);
}

void LevelFour::implementPenalty(){
  if(theGrid.lock()->justClearedRow()) unclearedCounter = 0;
  else unclearedCounter++;
  
  if(unclearedCounter == 5){
    for(int row = theGrid.lock()->getHeight()-1; row >= 0; --row){
      if(!theGrid.lock()->cellOccupied(row, theGrid.lock()->getWidth()/2)){
        theGrid.lock()->setCell(row,
                                theGrid.lock()->getWidth()/2,
                                Cell{Content::Extra, row, theGrid.lock()->getWidth()/2, -1, Level::lvl4, -1});
        break;
      }
    } unclearedCounter = 0;
  }
}
