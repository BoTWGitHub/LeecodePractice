/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionFind{
public:
    UnionFind(int size){
        root = vector<int>(size);
        rank = vector<int>(size, 1);
        numOfGroup = size;
        for(int i=0;i<size;i++) root[i]=i;
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        if(find(x)!=find(y)){
            if(rank[find(x)]<rank[find(y)]) root[find(x)] = find(y);
            else if(rank[find(x)]>rank[find(y)]) root[find(y)] = find(x);
            else{
                root[find(y)] = find(x);
                rank[find(x)]++;
            }
            numOfGroup--;
        }
    }
    bool isConnect(int x, int y){
        return find(x)==find(y);
    }
    int getNumOfGroup(){
        return numOfGroup;
    }
private:
    vector<int> root;
    vector<int> rank;
    int numOfGroup;
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        UnionFind uf(row*col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0 || i==0 || j==0 || i==row-1 || j==col-1){
                    if(grid[i][j]==1) bfs(grid, i, j, uf);
                    else uf.connect(0, i*col+j);
                }
            }
        }
        return uf.getNumOfGroup()-1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    void bfs(vector<vector<int>>& grid, int x, int y, UnionFind& uf){
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y]=0;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            uf.connect(0, p.first*grid[0].size()+p.second);
            for(int d=0;d<4;d++){
                int dx = p.first+dirs[d];
                int dy = p.second+dirs[d+1];
                if(dx<0 || dx>=grid.size()
                || dy<0 || dy>=grid[0].size()
                || grid[dx][dy]==0) continue;
                grid[dx][dy]=0;
                q.push({dx, dy});
            }
        }
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << solution.numEnclaves(grid) << endl;

    grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    cout << solution.numEnclaves(grid) << endl;
    return 0;
}