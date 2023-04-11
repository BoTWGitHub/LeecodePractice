/*
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size(), -1);
        for(int i=0;i<grid[0].size();i++){
            int temp = i;
            int j;
            for(j=0;j<grid.size();j++){
                int next = temp+grid[j][temp];
                if(next>=0 && next<grid[0].size() && grid[j][next]==grid[j][temp]){
                    temp = next;
                }
                else{
                    break;
                }
            }
            if(j==grid.size()){
                res[i] = temp;
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;
    vector<int> res;

    grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    res = solution.findBall(grid);
    printVector(res);

    grid = {{-1}};
    res = solution.findBall(grid);
    printVector(res);

    grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    res = solution.findBall(grid);
    printVector(res);
    return 0;
}