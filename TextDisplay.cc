#include <vector>
#include <iostream>
#include "type.h"
#include "TextDisplay.h"
using namespace std;

TextDisplay::TextDisplay(vector <vector <Cell*>> &board)
{
    // for every Cell::type create a point in this->board
    for (auto & row : board){
        vector <char *> temp;
        for (auto & cell : row){
            temp.push_back( &(cell->type) );
        }
        (this->board).push_back(temp);
    }
}

// erase the first linNum vectors in board
void TextDisplay::update(int lineNum)
{ board.erase( board.begin(), board.begin() + lineNum ); }

std::ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
    for (auto & row : td.board){
        for (auto & cell : row){
            out << *cell;
        }
        out << endl;
    }
    return out;
}
