/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        size = n;
        result = 0;
        vector<bool> col = vector<bool>(n);
        vector<bool> dia = vector<bool>(2*n-1);
        vector<bool> adia = vector<bool>(2*n-1);
        backtrack(col, dia, adia);
        return result;
    }
private:
    int size = 0;
    int result = 0;
    void backtrack(vector<bool> &col, vector<bool> &dia, vector<bool> &adia, int row=0){
        if(row==size){
            result++;
            return;
        }
        for(int i=0;i<size;i++){
            if(col[i]){
                continue;
            }
            if(dia[row-i+size-1]){
                continue;
            }
            if(adia[row+i]){
                continue;
            }
            col[i] = true;
            dia[row-i+size-1] = true;
            adia[row+i] = true;
            backtrack(col, dia, adia, row+1);
            col[i] = false;
            dia[row-i+size-1] = false;
            adia[row+i] = false;
        }
    }
};

int main(void){
    Solution solution;
    int n = 4;
    cout << solution.totalNQueens(n) << endl;

    return 0;
}