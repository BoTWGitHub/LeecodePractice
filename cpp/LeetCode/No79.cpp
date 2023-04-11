/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells
, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        end = word.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(backtrack(0, i, j, board, word)) return true;
            }
        }
        return false;
    }
private:
    int row;
    int col;
    int end;
    bool backtrack(int step, int x, int y, vector<vector<char>> &board, string &word){
        if(step==end){
            return true;
        }

        if(x<0 || x>=row
        || y<0 || y>=col
        || board[x][y]!=word[step]){
            return false;
        }

        board[x][y] = ' ';
        if(backtrack(step+1, x+1, y, board, word)) return true;
        if(backtrack(step+1, x-1, y, board, word)) return true;
        if(backtrack(step+1, x, y+1, board, word)) return true;
        if(backtrack(step+1, x, y-1, board, word)) return true;
        board[x][y] = word[step];

        return false;
    }
};

int main(){
    Solution solution;

    vector<vector<char>> board = {{'C','A','A'},
                                  {'A','A','A'},
                                  {'B','C','D'}};
    string word = "AABA";
    cout << solution.exist(board, word) << endl;
    return 0;
}
