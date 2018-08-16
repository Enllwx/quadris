#include "hintgenerator.h"
#include "grid.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


void printBoard(vector <vector <Cell>> board);

Block HintGenerator::moveByWeight(Block b){
    Block moved = b;
    moved.setRow(b.getRow()+b.getWeight());
    
    if(validPosition(moved)) return moved;
    return b;
}


Block HintGenerator::cwRotate(Block b){
    int width = b.getWidth();
    Block rotated = b;
    
    std::vector<Cell> oldArea = b.getArea();
    std::vector<Cell> newArea;
    for(int i=0; i<4; ++i)
        // Following 3 lines is the key that makes the rotation work!
        //   First we find the smartest rectangle that contains the block;
        //   then rotate the rectangle without cells that have not be covered
        newArea.emplace_back(Cell{oldArea[i].content,
            (b.getRow() - width + 1) + (oldArea[i].col - b.getCol()),
            b.getCol() + (b.getRow() - oldArea[i].row)});
    
    rotated.setArea(newArea);
    rotated.setRotation((b.getRotation()+1) % 4);
    
    if(validPosition(rotated)) return rotated;
    return b;
}


Block HintGenerator::rotateClock(Block b){
    return moveByWeight(cwRotate(b));
}


Block HintGenerator::rotateCounter(Block b){
    return moveByWeight(cwRotate(cwRotate(cwRotate(b))));
}


Block HintGenerator::moveDown(Block b){
    Block moved = b;
    moved.setRow(b.getRow()+1);
    
    if(validPosition(moved)) return moveByWeight(moved);
    return moveByWeight(b);
}


Block HintGenerator::moveLeft(Block b){
    Block moved = b;
    moved.setCol(b.getCol()-1);
    
    if(validPosition(moved)) return moveByWeight(moved);
    return moveByWeight(b);
}


Block HintGenerator::moveRight(Block b){
    Block moved = b;
    moved.setCol(b.getCol()+1);
    
    if(validPosition(moved)) return moveByWeight(moved);
    return moveByWeight(b);
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


bool HintGenerator::visited(Block b) const
{  cout << !visit[b.getRow()][b.getCol()][b.getRotation()] << endl;  return visit[b.getRow()][b.getCol()][b.getRotation()];  }



bool HintGenerator::validPosition(Block newB) const
{
    vector<Cell> area = newB.getArea();
    
    for(int i=0; i<4; ++i){
        int row = area[i].row;
        int col = area[i].col;
        
        if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) return false;
        if ( !board[row][col].temp
            && board[row][col].content != Content::Empty ) return false;
    } return true;
}



int HintGenerator::lineEliminate(Block b) const
{
    vector <int> RowCounter;
    for (auto Bcell : b.getArea()){
        int row = Bcell.row;

        int noElimination = WIDTH;
        for (int col = 0; col<WIDTH; col++){
            if ( (board[row][col]).content == Content::Empty ) break;
            else noElimination--;
        }
        
        bool addNewLine = true;
        if ( !noElimination ) {
            for (auto checkedRow : RowCounter){
                if (checkedRow == row) addNewLine = false;
            }
            if ( addNewLine ) RowCounter.push_back(row);
        }
    }
    return RowCounter.size();
}



// if there is no hole, it will return -1
int HintGenerator::aboveThehole(Block b) const{
    
    int aboveTheHole = -1;
    for (auto Bcell : b.getArea()){
        int lineCounter = 0;
        
        int row = Bcell.row;
        int col = Bcell.col;
        while (row >= 0) {
            if ( (board[row][col]).content == Content::Empty )
            { lineCounter = 0; aboveTheHole += lineCounter; break; }
            row++;
        }
    }
    return aboveTheHole;
}


int HintGenerator::touchThefloot(Block b) const
{
    int counter = 0;
    vector <Cell> area = b.getArea();
    for (int i=0; i<4; i++){
        if (area[i].row == HEIGHT-1) counter++;
    }
    return counter;
}



int HintGenerator::lineCounter(Block b) const
{
    int counter = 0;
    for (auto Bcell : b.getArea()){
        counter += Bcell.row;
    }
    return counter;
}



int HintGenerator::underEdges(Block b) const
{
    int counter = 0;
    for (auto Bcell : b.getArea()){
        int row = Bcell.row;
        int col = Bcell.col;
        if (col == 0 ||
            (board[row][col]).content != Content::Empty )
            counter++;
    }
    return counter;
}



float HintGenerator::scoreCounter(Block b) const
{
    float score = 0;
    /*
    score += lineEliminate(b) * 0.5;
    score += underEdges(b) * 0.7;
    score += lineCounter(b) * 0.4;
    score += touchThefloot(b) * 0.4;
    int ATH = aboveThehole(b);
    if (ATH == -1){ score+=1; }
    else if (ATH == 0){ score-=0.7; }
    else if (ATH > 0){ score-= pow(0.7, ATH); }
    return score;
     */
    score += lineEliminate(b) * A;
    score += underEdges(b) * B;
    score += lineCounter(b) * C;
    score += touchThefloot(b) * D;
    int ATH = aboveThehole(b);
    if (ATH == -1){ score+=E; }
    else if (ATH == 0){ score-=F; }
    else if (ATH > 0){ score-= pow(G, ATH); }
    return score;
}



void HintGenerator::betterHint(Block b)
{
    int row = b.getRow();
    int col = b.getCol();
    int rot = b.getRotation();
    
    if ( visit[row][col][rot] ) return;
    visit[row][col][rot] = 1;
    int tempScore = scoreCounter(b);
    
    ////////////////////////////////////////////////////
    cout << endl;
    cout << endl;
    cout << b;
    cout << row << "  " << col <<endl;
    cout << hintGrade << " (hintGrade)  vs  " << col << " (tempGrade)"<<endl;
    cout << endl;
    ////////////////////////////////////////////////////
    
    if ( tempScore >= hintGrade ){
        hintGrade = tempScore;
        hintBlock = b;
    }
    // "left "
    Block left = moveLeft(b); betterHint(left);
    // "right "
    Block right = moveRight(b); betterHint(right);
    // "drown "
    Block down = moveDown(b); betterHint(down);
    // "clock "
    Block clock = rotateClock(b); betterHint(clock);
    
    ////////////////////////////////////////////////////////
    for (auto row : visit){
        for (auto col : row){
            int sum = 0;
            for (auto rot: col){
                sum = sum + rot;
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    ////////////////////////////////////////////////////////
}



HintGenerator::HintGenerator(Block b, vector<vector<Cell>> board)
    : board{board}
{
    for(int row = 0; row < HEIGHT; ++row){
        vector <vector<bool>> temp;
        for(int col = 0; col < WIDTH; ++col){
            vector <bool> temppp;
            temppp.push_back(0);
            temppp.push_back(0);
            temppp.push_back(0);
            temppp.push_back(0);
            temp.emplace_back(temppp);
        }
        visit.emplace_back(temp);
    }
    betterHint(b);
}

Block HintGenerator::getHint(){ return hintBlock; }


