#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ifstream infile( "sequence.txt" );

int main(int argc, const char * argv[]) {
    
    //grid g; // board
    string cmd;
    string numCmds[] = {"right", "left", "down", "drop",
                        "levelup", "leveldown"};
    string otherCmds[] = {"restart", "hint", "norandom"};
    
    try{
    while (cin >> cmd) {
        unsigned long size = cmd.size();
        string subcmd = cmd.substr(0, size);
        if (size >= 2 &&
            size <= numCmds[0].size() &&
            cmd == otherCmds[0].substr(0, size)) {
            // when command is "restart"
            // ...
        }
        else if (size <= numCmds[1].size() &&
                 cmd == otherCmds[1].substr(0, size)) {
            // when command is "hint"
            // ...
        }
        else if (size <= numCmds[2].size() &&
                 cmd == otherCmds[2].substr(0, size)){
            // when command is "norandom"
            
            // if open file fails
            if ( infile.fail() ){ return 0; }
            string fromFile;
            infile >> fromFile;             // not sure about this ....
            
            // ...
        }
        else if (cmd == "I" || cmd == "J" || cmd == "L") {
            // when command is "I", "J", or "L"
            // ...
        }
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
                    // ...
                }
                else if (size >= 3 &&
                         size <= numCmds[0].size() &&
                         subcmd == numCmds[1].substr(0, size)){
                    // when command is "left"
                    // ...
                }
                else if (size >= 2 &&
                         size <= numCmds[0].size() &&
                         subcmd == numCmds[2].substr(0, size)){
                    // when command is "down"
                    // ...
                }
                else if (size >= 2 &&
                         size <= numCmds[0].size() &&
                         subcmd == numCmds[3].substr(0, size)){
                    // when command is "drop"
                    // ...
                }
                else if (size >= 6 &&
                         size <= numCmds[0].size() &&
                         subcmd == numCmds[4].substr(0, size)){
                    // when command is "levelup"
                    // ...
                }
                else if (size >= 6 &&
                         size <= numCmds[0].size() &&
                         subcmd == numCmds[5].substr(0, size)){
                    // when command is "leveldown"
                    // ...
                } else {
                    // when the command does not exists
                }
            }
        }
    }
    } catch (ios::failure &) {}  // Any I/O failure quits)
}
