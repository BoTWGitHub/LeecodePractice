/*
You are given a 0-indexed m x n binary matrix grid. 
You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1).

Return true if there is a path from (0, 0) to (m - 1, n - 1) that visits an equal number of 0's and 1's. 
Otherwise return false.
*/
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    bool isThereAPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m+n-1)%2==1) return false;
        std::queue<std::vector<int>> q;
        q.push({0,0,0});
        while(!q.empty()){
            std::vector<int> v = q.front();
            q.pop();
            v[2]+=grid[v[0]][v[1]];
            if(v[0]==m-1 && v[1]==n-1){
                if(v[2]==(m+n-1)/2) return true;
            }
            else{
                if(v[0]+1<m) q.push({v[0]+1, v[1], v[2]});
                if(v[1]+1<n) q.push({v[0], v[1]+1, v[2]});
            }
        }
        return false;
    }
};

int main(void){

    return 0;
}