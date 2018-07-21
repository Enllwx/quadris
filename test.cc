#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "block.h"
#include "type.h"
#include "difficulty.h"
#include "levelzero.h"
#include "grid.h"
#include "blockholder.h"
#include "hintgenerator.h"

using namespace std;

int main(){
  string loadPath = "sequence.txt";
  
  shared_ptr<Grid> g(new Grid());
  g->setLoadPath("miao");
    
  g->init();
  cout << *g;
  g->mutate(Move::Drop);
  cout << *g;
  g->mutate(Move::Drop);
  cout << *g;
  g->changeShape(Shape::Iblock);
  g->mutate(Move::Rotate);
  g->mutate(Move::Right, 3);
  cout << *g;
  g->mutate(Move::Drop);
  cout << *g;
  g->changeShape(Shape::Iblock);
  g->mutate(Move::Rotate);
  g->mutate(Move::Right, 2);
  cout << *g;
  g->mutate(Move::Down, 9);
  cout << *g;
  g->changeShape(Shape::Zblock);
  cout << *g;
  
  //HintGenerator hg(Block(Shape::Lblock), &g);
  
  // for(int i=0; i<11; ++i){
  //   g->mutate(Move::Rotate);
  //   g->mutate(Move::Right, i);
  //   g->mutate(Move::Drop);
  //   cout << *g;
  // }

  // g->mutate(Move::Right, 1);
  // g->changeShape(Shape::Tblock);
  // cout << *g;
  //g->mutate(Move::Down, 10);
  
  //g->hint();
  //cout << *g;
  //cout << *g;
  //HintGenerator hg(g);
  //Block c = hg.generateHint();
  //cout << "Hint = " << c.getRow() << ", " << c.getCol() << endl;
  //cout << c;
  
  //cout << hg.score(Cell{Content::Z, 16, 8, 0}) << endl;
  //cout << hg.score(Cell{Content::Z, 17, 9, 0}) << endl;
  // g->mutate(Move::Drop);
  // cout << *g;
  // g->mutate(Move::Right, 2);  
  // cout << *g;
  // g->mutate(Move::Drop);
  // cout << *g;
  // g->mutate(Move::Rotate, 2);
  // cout << *g;
  // g->mutate(Move::Right);
  // cout << *g;
  // g->mutate(Move::Drop);
  // cout << *g;
}
