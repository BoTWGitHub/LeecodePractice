/*
According to Wikipedia's article: 
"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

 - Any live cell with fewer than two live neighbors dies as if caused by under-population.
 - Any live cell with two or three live neighbors lives on to the next generation.
 - Any live cell with more than three live neighbors dies, as if by over-population.
 - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. 
Given the current state of the m x n grid board, return the next state.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int s = 0;
                for(vector<int> dir : dirs){
                    int dx = i+dir[0];
                    int dy = j+dir[1];
                    if(dx<0 || dx>=m || dy<0 || dy>=n) continue;
                    s+=temp[dx][dy];
                }
                if(board[i][j]==0 && s==3) board[i][j]=1;
                else if(board[i][j]==1 && (s<2 || s>3)) board[i][j]=0;
            }
        }
    }
private:
    const vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};

int main(void){
    Solution solution;
    vector<vector<int>> board;

    board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    solution.gameOfLife(board);
    print2DVector(board);

    board = {{1,1},{1,0}};
    solution.gameOfLife(board);
    print2DVector(board);
    return 0;
}