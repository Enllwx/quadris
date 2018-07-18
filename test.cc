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
  g.mutate(Move::Down, 15);
  cout << g;
  g.mutate(Move::Drop);
  cout << g;
  g.mutate(Move::Right, 2);
  g.mutate(Move::Drop);
  cout << g;
  g.mutate(Move::Right, 4);
  g.mutate(Move::Drop);
  cout << g;
  g.mutate(Move::Right, 6);
  g.mutate(Move::Drop);
  cout << g;
  g.mutate(Move::Right, 8);
  g.mutate(Move::Drop);
  cout << g;
  g.mutate(Move::Rotate);
  g.mutate(Move::Right, 10);
  g.mutate(Move::Down, 1);
  cout << g;
  g.mutate(Move::Drop);
 cout << g;
  cout << "success" << endl;
}
