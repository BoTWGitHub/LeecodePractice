/*
You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<pair<int, pair<int, int>>
                     , vector<pair<int, pair<int, int>>>
                     , greater<pair<int, pair<int, int>>>> minHeap;
                     
        for(int i=0;i<forest.size();i++){
            for(int j=0;j<forest[0].size();j++){
                if(forest[i][j]>1){
                    minHeap.push({forest[i][j], {i, j}});
                }
            }
        }

        int res = 0;
        pair<int, int> pos = {0, 0};
        while(!minHeap.empty()){
            pair<int, pair<int, int>> next = minHeap.top();
            minHeap.pop();
            int path = shortestPath(forest, pos, next.second);
            if(path==-1) return -1;
            res+=path;
            pos = next.second;
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    int shortestPath(vector<vector<int>>& forest, pair<int, int> &start, pair<int, int> &end){
        if(start==end) return 0;
        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        int res = 0;
        while(!q.empty()){
            int size=q.size();
            res++;
            for(int i=0;i<size;i++){
                pair<int, int> pos = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int dx = pos.first+dirs[j];
                    int dy = pos.second+dirs[j+1];
                    if(dx==end.first && dy==end.second) return res;

                    if(dx<0 || dx>=forest.size() 
                    || dy<0 || dy>=forest[0].size() 
                    || forest[dx][dy]==0 || visited[dx][dy]) continue;

                    visited[dx][dy]=true;
                    q.push({dx, dy});
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> forest;

    forest = {{1,2,3},{0,0,4},{7,6,5}};
    cout << solution.cutOffTree(forest) << endl;

    forest = {{1,2,3},{0,0,0},{7,6,5}};
    cout << solution.cutOffTree(forest) << endl;

    forest = {{2,3,4},{0,0,5},{8,7,6}};
    cout << solution.cutOffTree(forest) << endl;

    forest = {{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
    cout << solution.cutOffTree(forest) << endl;
    return 0;
}