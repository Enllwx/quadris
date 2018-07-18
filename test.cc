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

using namespace std;

int main(){
  Grid g;// = new Grid();
  cout << g;
  // for(int i=0; i<15; ++i){
  //   g.mutate(Move::Down);
  //   cout << g;
  // }
  g.mutate(Move::Down);
  cout << g;
  //g.mutate(Move::Rotate);  
  //cout << g;
  //g.mutate(Move::Drop);  
  //cout << g;
  //g.mutate(Move::Right);
  //Difficulty *d = new LevelZero(g);
  //bh.mutate(Move::Down);
  //cout << b.getRow() << ", " << b.getCol() << endl;
  //b = d->moveDown(b);
  //cout << b.getRow() << ", " << b.getCol() << endl;
  //Block b(Shape::Iblock);
  //cout << b.getRow() << ", " << b.getCol() << endl;
  //delete g;
  //cout << g;
  //cout << g;
  cout << "success" << endl;
}
