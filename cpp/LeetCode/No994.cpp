/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        if(fresh==0) return 0;
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                pair<int, int> p = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int dx = p.first+dirs[j];
                    int dy = p.second+dirs[j+1];
                    if(dx<0 || dx>=grid.size() || dy<0 || dy>=grid[0].size() || grid[dx][dy]!=1) continue;
                    grid[dx][dy] = 2;
                    fresh--;
                    if(fresh==0) return res;
                    q.push({dx, dy});
                }
            }
        }
        return -1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << solution.orangesRotting(grid) << endl;

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout << solution.orangesRotting(grid) << endl;

    grid = {{0,2}};
    cout << solution.orangesRotting(grid) << endl;
    return 0;
}