#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "grid.h"
#include "type.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
  // first check the argument command
  int TextOnly = 0;
  int StartLevel = 0;
  string InputFile = "sequence.txt";
  string SeedEqual = "false";
  // if seed is 0, it will be same random value
  /*
    for (int i=1; i<argc; i++){
        
    if (string(argv[i]) == "-text"){
    TextOnly = true;
    }
    else if (string(argv[i]) == "-seed"){
    SeedEqual = argv[i+1];
    }
    else if (string(argv[i]) == "-scriptfile"){
    if (i+1 < argc) InputFile = argv[i+1];
    }
    else if (string(argv[i]) == "-startlevel"){
    istringstream num(argv[i+1]);
    num >> StartLevel;
    }
    }
  */
  /*  default code */
  //cout << "TextOnly:     " << TextOnly << endl;
  //cout << "Startlevel:   " << StartLevel << endl;
  //cout << "InputFile:    " << InputFile << endl;
  //cout << "SeedEqual:    " << SeedEqual << endl;

  ifstream infile( InputFile );
    
    
  shared_ptr<Grid> g(new Grid());
  g->init();
  cout << *g;
  //DON' T MODIFY CODE BELOW!!!
  ///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////
  string cmd;
  string numCmds[] = {"right", "left", "down", "drop", "levelup", "leveldown"};
  string otherCmds[] = {"restart", "hint", "norandom", "random", "clockwise", "counterclockwise"};
    
  try{
    while (cin >> cmd) {
      unsigned long size = cmd.size();
      string subcmd = cmd.substr(0, size);

      if(cmd == "q") break;
      
      if (size >= 2 && size <= otherCmds[0].size()
          && cmd == otherCmds[0].substr(0, size)) {
        // when command is "restart"
        g->clear();
        //........
        cout << *g;
      }
      else if (size <= otherCmds[1].size() &&
               cmd == otherCmds[1].substr(0, size)) {
        // when command is "hint"
        g->hint();
        cout << *g;
      }
      else if (size <= otherCmds[2].size() &&
               cmd == otherCmds[2].substr(0, size)){
        // when command is "norandom"
        //........
      }
      else if (size >= 2 && size <= otherCmds[3].size() &&
               cmd == otherCmds[3].substr(0, size)){
        // when command is "random"
        //........
      }
      else if (size >= 2 && size <= otherCmds[4].size() &&
               cmd == otherCmds[4].substr(0, size)){
        // when command is "rotate"
        g->mutate(Move::Rotate);
        cout << *g;
      }
      else if (size >= 2 && size <= otherCmds[5].size() &&
               cmd == otherCmds[5].substr(0, size)){
        // when command is "counterotate"
        g->mutate(Move::CounterRotate);
        cout << *g;
      }
      else if (cmd == "I" || cmd == "J" || cmd == "L") {
        // when command is "I", "J", or "L"
        cout << "I  J  L" << endl;
        //........
      }
      if (size >= 2 &&
          size <= numCmds[0].size() &&
          cmd == numCmds[0].substr(0, size)){
        // when command is "right"
        g->mutate(Move::Right);
        cout << *g;
      }
      else if (size >= 3 &&
               size <= numCmds[1].size() &&
               cmd == numCmds[1].substr(0, size)){
        // when command is "left"
        g->mutate(Move::Left);
        cout << *g;
      }
      else if (size >= 2 &&
               size <= numCmds[2].size() &&
               cmd == numCmds[2].substr(0, size)){
        // when command is "down"
        g->mutate(Move::Down);
        cout << *g;
      }
      else if (size >= 2 &&
               size <= numCmds[3].size() &&
               cmd == numCmds[3].substr(0, size)){
        // when command is "drop"
        g->mutate(Move::Drop);
        cout << *g;
      }
      else if (size >= 6 &&
               size <= numCmds[4].size() &&
               cmd == numCmds[4].substr(0, size)){
        // when command is "levelup"
        if (StartLevel < 4) StartLevel+=1;
        g->changeLevel(StartLevel);        
      }
      else if (size >= 6 &&
               size <= numCmds[5].size() &&
               cmd == numCmds[5].substr(0, size)){
        // when command is "leveldown"
        if (StartLevel) StartLevel-=1;
        g->changeLevel(StartLevel);
      }
     
      ////////////////////////////////////////////////////////////
      ///         command with 0~9 as prefix                   ///
      ////////////////////////////////////////////////////////////
     
      else {
        istringstream num(cmd);
        int n;
        if (num >> n) {
          // if first string is num, reset subcmd, size
          subcmd = cmd.substr(1, size - 1);
          size -= 1;
                    
          if (size >= 2 &&
              size <= numCmds[0].size() &&
              subcmd == numCmds[0].substr(0, size)){
            // when command is "right"
            g->mutate(Move::Right, n);
            cout << *g;
          }
          else if (size >= 3 &&
                   size <= numCmds[1].size() &&
                   subcmd == numCmds[1].substr(0, size)){
            // when command is "left"
            g->mutate(Move::Left,n);
            cout << *g;
          }
          else if (size >= 2 &&
                   size <= numCmds[2].size() &&
                   subcmd == numCmds[2].substr(0, size)){
            // when command is "down"
            g->mutate(Move::Down,n);
            cout << *g;
          }
          else if (size >= 2 &&
                   size <= numCmds[3].size() &&
                   subcmd == numCmds[3].substr(0, size)){
            // when command is "drop"
            g->mutate(Move::Drop,n);
            cout << *g;
          }
          else if (size >= 6 &&
                   size <= numCmds[4].size() &&
                   subcmd == numCmds[4].substr(0, size)){
            // when command is "levelup"
            if (StartLevel + n <= 4) StartLevel += n;
          }
          else if (size >= 6 &&
                   size <= numCmds[5].size() &&
                   subcmd == numCmds[5].substr(0, size)){
            // when command is "leveldown"
            if (StartLevel - n >= 0) StartLevel -= n;
          }
          else {} // when the command does not exists
        }
      }
    }
  } catch (ios::failure &) {}  // Any I/O failure quits)
}

/*
  clo
  drop
  clo
  right
  drop
  clo
  2right
  drop
  3right
  drop
  7right
  drop

 
*/
