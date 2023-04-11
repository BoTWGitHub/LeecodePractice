/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                if(board[i][j]=='O'){
                    bfs(board, i, j);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    int rows;
    int cols;
    void bfs(vector<vector<char>>& board, int x, int y){
        bool res = true;
        board[x][y] = '.';
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int dx = i+dirs[d];
                int dy = j+dirs[d+1];
                if(dx<0 || dx>=rows || dy<0 || dy>=cols || board[dx][dy]!='O') continue;
                if(dx==0 || dx==rows-1 || dy==0 || dy==cols-1) res = false;
                board[dx][dy] = '.';
                q.push({dx, dy});
            }
        }
        if(res){
            board[x][y] = 'X';
            q.push({x, y});
            while(!q.empty()){
                auto [i, j] = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int dx = i+dirs[d];
                    int dy = j+dirs[d+1];
                    if(dx<0 || dx>=board.size() || dy<0 || dy>=board[0].size() || board[dx][dy]!='.') continue;
                    board[dx][dy] = 'X';
                    q.push({dx, dy});
                }
            }
        }
    }
};

int main(void){
    Solution solution;
    vector<vector<char>> board;

    board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solution.solve(board);
    print2DVector(board);

    board = {{'X'}};
    solution.solve(board);
    print2DVector(board);

    board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    solution.solve(board);
    print2DVector(board);
    return 0;
}