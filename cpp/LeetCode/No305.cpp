/*
You are given an empty 2D binary grid grid of size m x n. 
The grid represents a map where 0's represent water and 1's represent land. 
Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. 
You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class UnionFind{
public:
    UnionFind(int n) : root(n), rank(n), numOfGroup(n){
        for(int i=0;i<n;i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]){
                root[rx] = ry;
            }
            else if(rank[rx]>rank[ry]){
                root[ry] = rx;
            }
            else{
                root[rx] = ry;
                rank[ry]++;
            }
            numOfGroup--;
        }
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int size = positions.size();
        vector<vector<int>> board(m, vector<int>(n, 0));
        int zeroCount = m*n;
        UnionFind uf(zeroCount);
        vector<int> res(size, 0);
        for(int i=0;i<size;i++){
            int x = positions[i][0];
            int y = positions[i][1];
            if(board[x][y]==0){
                board[x][y] = 1;
                zeroCount--;
                for(int d=0;d<4;d++){
                    int dx = x+dirs[d];
                    int dy = y+dirs[d+1];
                    if(dx>=m || dx<0 || dy>=n || dy<0 || board[dx][dy]==0) continue;
                    uf.connect(x*n+y, dx*n+dy);
                }
            }
            res[i] = uf.getNumOfGroup() - zeroCount;
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    int m;
    int n;
    vector<vector<int>> positions;
    vector<int> res;

    m = 3;
    n = 3;
    positions = {{0,0},{0,1},{1,2},{2,1}};
    res = solution.numIslands2(m, n, positions);
    printVector(res);

    m = 1;
    n = 1;
    positions = {{0,0}};
    res = solution.numIslands2(m, n, positions);
    printVector(res);

    m = 3;
    n = 3;
    positions = {{0,0},{0,1},{1,2},{1,2}};
    res = solution.numIslands2(m, n, positions);
    printVector(res);
    return 0;
}