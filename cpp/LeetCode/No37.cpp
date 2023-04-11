/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(9));
        vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(9));
        vector<vector<bool>> block = vector<vector<bool>>(9, vector<bool>(9));
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]!='.'){
                    int index = board[r][c] - '1';
                    row[r][index] = true;
                    col[c][index] = true;
                    block[r/3*3+c/3][index] = true;
                }
            }
        }
        backtrack(board, row, col, block);
    }
private:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &block, int r=0, int c=0){
        bool result = false;
        if(c==9){
            r++;
            if(r==9){
                return true;
            }
            c=0;
        }
        
        if(board[r][c]=='.'){
            for(int n=0;n<9;n++){
                if(!row[r][n] && !col[c][n] && !block[r/3*3+c/3][n]){
                    board[r][c] = '1' + n;
                    row[r][n] = true;
                    col[c][n] = true;
                    block[r/3*3+c/3][n] = true;
                    refresh2DVector<char>(board);
                    result = backtrack(board, row, col, block, r, c+1);
                    if(!result){
                        board[r][c] = '.';
                        row[r][n] = false;
                        col[c][n] = false;
                        block[r/3*3+c/3][n] = false;
                    }
                    else{
                        return result;
                    }
                }
            }
        }
        else{
            result = backtrack(board, row, col, block, r, c+1);
        }
        return result;
    }
};

int main(void){
    Solution solution;

    vector<vector<char>> board{
                                {'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}
                              };
    solution.solveSudoku(board);
    refresh2DVector<char>(board);
    return 0;
}