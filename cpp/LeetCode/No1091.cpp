/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

 - All the visited cells of the path are 0.
 - All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1 || grid.back().back()==1) return -1;
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                pair<int, int> p = q.front();
                if(p.first==grid.size()-1 && p.second==grid[0].size()-1){
                    return res;
                }
                q.pop();
                for(vector<int> dir : dirs){
                    int dx = p.first+dir[0];
                    int dy = p.second+dir[1];
                    if(dx>=0 && dx<grid.size() && dy>=0 && dy<grid[0].size() && grid[dx][dy]==0){
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
        }
        return -1;
    }
private:
    const vector<vector<int>> dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{0,1},{1,0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    grid = {{1,0,0},{1,1,0},{1,1,0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}