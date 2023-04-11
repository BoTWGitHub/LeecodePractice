/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style 
starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. 
Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. 
If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. 
You follow the ladder to square 3, but do NOT follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
*/
#include <iostream>
#include <queue>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat(n*n);
        int x = n-1, y = 0, d = 1;
        for(int i=0;i<n*n;i++){
            flat[i] = board[x][y];
            y+=d;
            if(y==n || y==-1){
                if(y==n) y--;
                else y++;
                x--;
                d*=-1;
            }
        }
        queue<int> q;
        q.push(0);
        int res = 0;
        flat[0] = -2;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(int j=1;j<7;j++){
                    int next = node+j;
                    if(next>=n*n) break;
                    else if(next==n*n-1) return res;
                    if(flat[next]==-2) continue;
                    else if(flat[next]==-1){
                        flat[next] = -2;
                        q.push(next);
                    }
                    else{
                        if(flat[next]==n*n) return res;
                        q.push(flat[next]-1);
                        flat[next] = -2;
                    }
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> board;

    board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    cout << solution.snakesAndLadders(board) << endl;

    board = {{-1,-1},{-1,3}};
    cout << solution.snakesAndLadders(board) << endl;

    board = {{-1,-1,-1},{-1,9,8},{-1,8,9}};
    cout << solution.snakesAndLadders(board) << endl;

    board = {{-1,-1,-1,30,-1,144,124,135,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,167,93,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,77,-1,-1,90,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,122,-1},{-1,-1,-1,23,-1,-1,-1,-1,-1,155,-1,-1,-1},{-1,-1,140,29,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,115,-1,-1,-1,109,-1,-1,5},{-1,57,-1,99,121,-1,-1,132,-1,-1,-1,-1,-1},{-1,48,-1,-1,-1,68,-1,-1,-1,-1,31,-1,-1},{-1,163,147,-1,77,-1,-1,114,-1,-1,80,-1,-1},{-1,-1,-1,-1,-1,57,28,-1,-1,129,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,87,-1,-1,-1}};
    cout << solution.snakesAndLadders(board) << endl;
    return 0;
}