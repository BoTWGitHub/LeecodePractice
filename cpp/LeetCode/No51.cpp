/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    int size;
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<bool> col = vector<bool>(n);
        vector<bool> dia = vector<bool>(2*n-1);
        vector<bool> adia = vector<bool>(2*n-1);
        vector<string> temp;
        backtrack(col, dia, adia, temp);
        return result;
    }
    void backtrack(vector<bool> &col, vector<bool> &dia, vector<bool> &adia, vector<string> &temp, int row = 0){
        if(row==size){
            result.push_back(temp);
            return;
        }
        string s = string(size, '.');
        for(int i=0;i<size;i++){
            if(col[i] || dia[row-i+size-1] || adia[row+i]){
                continue;
            }
            s[i] = 'Q';
            temp.push_back(s);
            col[i] = true;
            dia[row-i+size-1] = true;
            adia[row+i] = true;
            backtrack(col, dia, adia, temp, row+1);
            s[i] = '.';
            temp.pop_back();
            col[i] = false;
            dia[row-i+size-1] = false;
            adia[row+i] = false;
        }
    }
};

int main(void){
    Solution solution;
    
    int n = 4;
    print2DVector<string>(solution.solveNQueens(n));
    return 0;
}