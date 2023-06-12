/*
There is an m x n grid, where (0, 0) is the top-left cell and (m - 1, n - 1) is the bottom-right cell. 
You are given an integer array startPos where startPos = [startrow, startcol] indicates that initially, a robot is at the cell (startrow, startcol). 
You are also given an integer array homePos where homePos = [homerow, homecol] indicates that its home is at the cell (homerow, homecol).

The robot needs to go to its home. 
It can move one cell in four directions: left, right, up, or down, and it can not move outside the boundary. 
Every move incurs some cost. 
You are further given two 0-indexed integer arrays: rowCosts of length m and colCosts of length n.

If the robot moves up or down into a cell whose row is r, then this move costs rowCosts[r].
If the robot moves left or right into a cell whose column is c, then this move costs colCosts[c].
Return the minimum total cost for this robot to return home.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    int minCost(std::vector<int>& startPos, std::vector<int>& homePos, std::vector<int>& rowCosts, std::vector<int>& colCosts) {
        int res = 0;
        int rDif = homePos[0]-startPos[0];
        if(rDif!=0){
            int rDir = rDif/abs(rDif);
            while(startPos[0]!=homePos[0]){
                startPos[0]+=rDir;
                res+=rowCosts[startPos[0]];
            }
        }
        int cDif = homePos[1]-startPos[1];
        if(cDif!=0){
            int cDir = cDif/abs(cDif);
            while(startPos[1]!=homePos[1]){
                startPos[1]+=cDir;
                res+=colCosts[startPos[1]];
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> startPos;
    std::vector<int> homePos;
    std::vector<int> rowCosts;
    std::vector<int> colCosts;

    startPos = {1,0};
    homePos = {2,3};
    rowCosts = {5,4,3};
    colCosts = {8,2,6,7};
    std::cout << solution.minCost(startPos, homePos, rowCosts, colCosts) << std::endl;

    startPos = {0,0};
    homePos = {0,0};
    rowCosts = {5};
    colCosts = {26};
    std::cout << solution.minCost(startPos, homePos, rowCosts, colCosts) << std::endl;
    return 0;
}