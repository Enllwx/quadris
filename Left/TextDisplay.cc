#include <vector>
#include <iostream>
#include "score.h"
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

void TextDisplay::printText(int lvl, Shape NexBlock, scoreCounter* s) const
{
    cout << "Level:    " << lvl << endl;
    cout << "Score:    " << s->getTotal() << endl;
    cout << "Hi Score: " << s->getMax() << endl;
    
    cout << "-----------" << endl;
    
    for (auto row : board){
        for (auto cell : row){
            if (*cell == '-') cout << " ";
            else { cout << *cell; }
        }
        cout << endl;
    }
    
    cout << "-----------" << endl;
    
    cout << "Next:" << endl;
    //Iblock, Jblock, Oblock, Lblock, Sblock, Zblock, Tblock
    if (NexBlock == Shape::Iblock) {
        cout << "   " << endl << "IIII" << endl;
    } else if (NexBlock == Shape::Jblock) {
        cout << "J  " << endl << "JJJ" << endl;
    } else if (NexBlock == Shape::Lblock) {
        cout << "  L" << endl << "LLL" << endl;
    } else if (NexBlock == Shape::Oblock) {
        cout << "OO " << endl << "OO " << endl;
    } else if (NexBlock == Shape::Sblock) {
        cout << " SS" << endl << "SS " << endl;
    } else if (NexBlock == Shape::Zblock) {
        cout << "ZZ " << endl << " ZZ" << endl;
    } else if (NexBlock == Shape::Tblock) {
        cout << "TTT" << endl << " T " << endl;
    }
    cout << endl;
    return;
}
