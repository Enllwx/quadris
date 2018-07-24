#include <iostream>
#include "grid.h"
#include "type.h"
#include "textdisplay.h"
using namespace std;

void TextDisplay::setGrid(vector<vector <Cell>> * board){
    this->board = board;
}

std::ostream &operator<<(std::ostream &out, TextDisplay &td){
    
    out << "  ";
    for (int col=0; col<WIDTH; col++) out << col % 10;
    out << endl;
    cout << " +-----------" << endl;
    
    for (int row=0; row<HEIGHT; row++){
        out << row % 10 << "|";
        for (int col=0; col<WIDTH; col++){
            switch ( (*(td.board))[row][col].content ) {
                case Content::Empty : cout << " "; break;
                case Content::Extra : cout << "*"; break;
                case Content::Hint : cout << "?"; break;
                case Content::I : cout << "I"; break;
                case Content::J : cout << "J"; break;
                case Content::L : cout << "L"; break;
                case Content::T : cout << "T"; break;
                case Content::O : cout << "O"; break;
                case Content::S : cout << "S"; break;
                case Content::Z : cout << "Z"; break;
            }
        }
        cout << endl;
    }
    cout << " +-----------" << endl;
    for (int row=0; row<HEIGHT; row++){
        for (int col=0; col<WIDTH; col++){
            
            // if the cell is temperary occuped by content (hint or currentBlock)
            if ( (*td.board)[row][col].temperary ){
                (*td.board)[row][col].temperary = false;
                (*td.board)[row][col].content = Content::Empty;
            }
        }
    }
    return out;
}

