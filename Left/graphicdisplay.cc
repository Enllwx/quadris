#include <vector>
#include <string>
#include "score.h"
#include "type.h"
#include "graphicdisplay.h"
#include "window.h"
using namespace std;
const int UNIT = 5;

// ctor
GraphicDisplay::GraphicDisplay(vector <vector <Cell*>> &board)
    : window{new Xwindow}
{
    // for every Cell::type create a point in this->board
    for (auto & row : board){
        vector <char *> temp;
        for (auto & cell : row){ temp.push_back( &(cell->type) ); }
        (this->board).push_back(temp);
    }
    
    // print initial graph
    window->fillRectangle( 3 * UNIT,0 * UNIT, 25 * UNIT, 11 * UNIT, 0);
    window->drawString(0*UNIT, 0, "Level:    0");
    window->drawString(1*UNIT, 0, "Score:    0");
    window->drawString(2*UNIT, 0, "Hi Score: 0");
    for (int i=0; i<11; i++){
        window->fillRectangle(3*UNIT, i*UNIT, 5, 3, 8);
        window->fillRectangle(21*UNIT, i*UNIT, 5, 3, 8);
    }
    window->drawString(22*UNIT, 0, "Next: ");
    
    
}

// erase the first linNum vectors in board
void GraphicDisplay::update(int lineNum)
{ board.erase( board.begin(), board.begin() + lineNum ); }
    
// notify() draw the graph on window
void GraphicDisplay::drawGraph(int lvl, Shape NexBlock, scoreCounter* s) const
{
            ////////////////////////////////////////
            //  { Shape::Iblock, 1 },  /* red    */
            //  { Shape::Jblock, 2 },  /* blue   */
            //  { Shape::Lblock, 3 },  /* yellow */
            //  { Shape::Oblock, 4 },  /* green  */
            //  { Shape::Sblock, 5 },  /* brown  */
            //  { Shape::Zblock, 6 },  /* purple */
            //  { Shape::Tblock, 7 },  /* orange */
            ////////////////////////////////////////
    
    window->drawString(0*UNIT, 0, "Level:    " + to_string(lvl) );
    window->drawString(1*UNIT, 0, "Score:    " + to_string(s->getTotal()) );
    window->drawString(2*UNIT, 0, "Hi Score: " + to_string(s->getMax()) );
    
    for (int row=0; row<18; row++){
        for (int col=0; col<18; col++){
            if ( *(board[row][col]) == '-' ){
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 0);
            } else if ( *(board[row][col]) == 'I' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 1);
            } else if ( *(board[row][col]) == 'J' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 2);
            } else if ( *(board[row][col]) == 'L' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 3);
            } else if ( *(board[row][col]) == 'O' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 4);
            } else if ( *(board[row][col]) == 'S' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 5);
            } else if ( *(board[row][col]) == 'Z' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 6);
            } else if ( *(board[row][col]) == 'T' ) {
                window->fillRectangle( (row+4) * UNIT, col * UNIT, UNIT, 7);
            }
        }
    }
    
    window->drawString(22*UNIT, 0, "Next: ");
    //Iblock, Jblock, Oblock, Lblock, Sblock, Zblock, Tblock
    if (NexBlock == Shape::Iblock) {
        window->fillRectangle( 24 * UNIT,0 * UNIT , UNIT, 1);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 1);
        window->fillRectangle( 24 * UNIT,2 * UNIT , UNIT, 1);
        window->fillRectangle( 24 * UNIT,3 * UNIT , UNIT, 1);
        // cout << "   " << endl << "IIII" << endl;
    } else if (NexBlock == Shape::Jblock) {
        window->fillRectangle( 23 * UNIT,0 * UNIT , UNIT, 2);
        window->fillRectangle( 24 * UNIT,0 * UNIT , UNIT, 2);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 2);
        window->fillRectangle( 24 * UNIT,2 * UNIT , UNIT, 2);
        // cout << "J  " << endl << "JJJ" << endl;
    } else if (NexBlock == Shape::Lblock) {
        window->fillRectangle( 23 * UNIT,2 * UNIT , UNIT, 3);
        window->fillRectangle( 24 * UNIT,0 * UNIT , UNIT, 3);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 3);
        window->fillRectangle( 24 * UNIT,2 * UNIT , UNIT, 3);
        // cout << "  L" << endl << "LLL" << endl;
    } else if (NexBlock == Shape::Oblock) {
        window->fillRectangle( 23 * UNIT,0 * UNIT , UNIT, 4);
        window->fillRectangle( 23 * UNIT,1 * UNIT , UNIT, 4);
        window->fillRectangle( 24 * UNIT,0 * UNIT , UNIT, 4);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 4);
        // cout << "OO " << endl << "OO " << endl;
    } else if (NexBlock == Shape::Sblock) {
        window->fillRectangle( 23 * UNIT,1 * UNIT , UNIT, 5);
        window->fillRectangle( 23 * UNIT,2 * UNIT , UNIT, 5);
        window->fillRectangle( 24 * UNIT,0 * UNIT , UNIT, 5);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 5);
        // cout << " SS" << endl << "SS " << endl;
    } else if (NexBlock == Shape::Zblock) {
        window->fillRectangle( 23 * UNIT,0 * UNIT , UNIT, 6);
        window->fillRectangle( 23 * UNIT,1 * UNIT , UNIT, 6);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 6);
        window->fillRectangle( 24 * UNIT,2 * UNIT , UNIT, 6);
        // cout << "ZZ " << endl << " ZZ" << endl;
    } else if (NexBlock == Shape::Tblock) {
        window->fillRectangle( 23 * UNIT,0 * UNIT , UNIT, 7);
        window->fillRectangle( 23 * UNIT,1 * UNIT , UNIT, 7);
        window->fillRectangle( 23 * UNIT,2 * UNIT , UNIT, 7);
        window->fillRectangle( 24 * UNIT,1 * UNIT , UNIT, 7);
        // cout << "TTT" << endl << " T " << endl;
    }
    cout << endl;
    return;
}




