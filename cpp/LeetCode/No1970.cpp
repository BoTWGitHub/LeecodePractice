/*
There is a 1-based binary matrix where 0 represents land and 1 represents water. 
You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. 
You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day
, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. 
You can start from any cell in the top row and end at any cell in the bottom row. 
You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
*/
#include <iostream>
#include <queue>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        initUf(row*col+2);
        for(int i=0;i<cells.size();i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            if(y==0) connect(row*col, x*col+y);
            if(y==col-1) connect(row*col+1, x*col+y);
            grid[x][y] = 1;
            for(int d=0;d<dirs.size();d++){
                int dx = x+dirs[d][0];
                int dy = y+dirs[d][1];
                if(dx>=row || dx<0 || dy>=col || dy<0 || grid[dx][dy]==0) continue;
                connect(x*col+y, dx*col+dy);
            }
            if(isConnected(row*col, row*col+1)) return i;
        }
        return -1;
    }
private:
    const vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<int> root;
    vector<int> rank;
    void initUf(int n){
        root = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0;i<n;i++) root[i] = i;
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]) root[rx] = ry;
            else if(rank[ry]<rank[rx]) root[ry] = rx;
            else{
                root[rx] = ry;
                rank[ry]++;
            }
        }
    }
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
};

int main(void){
    Solution solution;
    int row;
    int col;
    vector<vector<int>> cells;

    row = 2;
    col = 2;
    cells = {{1,1},{2,1},{1,2},{2,2}};
    cout << solution.latestDayToCross(row, col, cells) << endl;

    row = 2;
    col = 2;
    cells = {{1,1},{1,2},{2,1},{2,2}};
    cout << solution.latestDayToCross(row, col, cells) << endl;

    row = 3;
    col = 3;
    cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout << solution.latestDayToCross(row, col, cells) << endl;
    return 0;
}