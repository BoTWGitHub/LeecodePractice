/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column 
and going in the bottom-right direction until reaching the matrix's end. 
For example, the matrix diagonal starting from mat{2}{0}, where mat is a 6 x 3 matrix, includes cells mat{2}{0}, mat{3}{1}, and mat{4}{2}.

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/
#include <iostream>
#include <queue>
#include "Debug\VectorDebug.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mem;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                 if(mem.count(i-j)==0){
                    mem[i-j] = priority_queue<int, vector<int>, greater<int>>();
                 }
                 mem[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j] = mem[i-j].top();
                mem[i-j].pop();
            }
        }
        return mat;
    }
};

class Solution2 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i=0, j=mat[0].size()-1;
        while(i<mat.size()){
            vector<int> temp;
            int x, y, z;
            x=i;
            y=j;
            while(x<mat.size() && y<mat[0].size()){
                temp.push_back(mat[x++][y++]);
            }
            sort(temp.begin(), temp.end());
            x=i;
            y=j;
            z=0;
            while(x<mat.size() && y<mat[0].size()){
                mat[x++][y++] = temp[z++];
            }
            if(j==0) i++;
            else j--;
        }
        return mat;
    }
};

int main(void){
    Solution solution;

    vector<vector<int>> mat;
    vector<vector<int>> res;

    mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    res = solution.diagonalSort(mat);
    print2DVector(res);

    mat = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    res = solution.diagonalSort(mat);
    print2DVector(res);

    return 0;
}