#include <iostream>
#include <vector>
#include "type.h"
#include "grid.h"
using namespace std;

// ctor
/*
int difficultyLevel;
vector <vector <Cell*>> board;
BlockHolder* theHolder;
TextDisplay* td;
GraphicDisplay* gd;
ScoreCounter* score;
int *difficultyLevel;
 */

Grid::Grid(int *difficulty, int textOnly)
{
    for (int i=0; i<18; i++){
        vector <Cell*> temp;
        for (int j=0; j<11; j++){
            temp.push_back(new Cell{i, j, '-'});
        }
        board.puch_back(temp);
    }
    theHolder = new BlockHolder{board};
    td = new TextDisplay{board};
    if (textOnly) gd = new GraphicDisplay{board};
    score = new scoreCounter;
    difficultyLevel = difficulty;
}

// update() the board (may eliminate lines)
void Grid::update()
{
    int eliminateNum = 0;
    bool checkEliminate = 1;
    
    while (checkEliminate){
        for (int i=0; i<11; i++){
            if (board[17][i]->type == ' '){
                checkEliminate = 0;
                break;
            }
        }
        
        if (checkEliminate){
            board.pop_back();
            vector <Cell*> temp;
            for (int i=0; i<11; i++) temp.push_back(new Cell{0,i,' '});
            board.insert(board.begin(), temp);
        }
    }
    
    if (eliminateNum){
        td->update(eliminateNum);
        if (gd) gd->update(eliminateNum);
        score->addScore(*difficultyLevel ,eliminateNum);
    }
}
// clear() clear the board
void Grid::clear()
{
    score->clear();
    theHolder->clear();
    for (int i=0; i<18; i++){
        for (int j=0; j<11; j++){
            board.back[i][j].type = '-';
        }
    }
}


// hint() give the best solution of current block
void Grid::hint() { theHolder->hint(); }

// gameOver() determine if the game is over
void Grid::gameOver()
{
    if ( theHolder->gameOver() ){
        cout << "GAME OVER !!!" << endl;
        cout << "Your score is " << score->getTotal() << endl;
        if (gd) gd->gameOver(score->getTotal());
    }
    
}

// changeLevel() change the difficult lvl
void Grid::changeLevel(int num) { *difficultyLevel = num; }

// mutate() change the current block
void Grid::mutate(int num, Move cmd){ theHolder->mutate(num, cmd); }

ostream& Grid::operator<<(std::ostream &out, const Grid &g)
{
    
}
