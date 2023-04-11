/*
On a 2D plane, we place n stones at some integer coordinate points. 
Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone
, return the largest possible number of stones that can be removed.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class UnionFind{
public:
    UnionFind(int size){
        root = vector<int>(size);
        rank = vector<int>(size, 1);
        for(int i=0;i<size;i++) root[i]=i;
        group = size;
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]) root[rx]=ry;
            else if(rank[rx]>rank[ry]) root[ry]=rx;
            else{
                root[ry] = rx;
                rank[rx]++;
            }
            group--;
        }
    }
    int getGroup(){
        return group;
    }
private:
    vector<int> root;
    vector<int> rank;
    int group;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int xCount = 0, yCount = 0;
        unordered_map<int, int> xMap, yMap;
        for(vector<int> stone : stones){
            if(xMap.count(stone[0])==0) xMap[stone[0]] = xCount++;
            if(yMap.count(stone[1])==0) yMap[stone[1]] = yCount++;
        }
        UnionFind uf(xCount+yCount);
        for(vector<int> stone : stones){
            uf.connect(xMap[stone[0]], yMap[stone[1]]+xCount);
        }
        return stones.size()-uf.getGroup();
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> stones;
    
    stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << solution.removeStones(stones) << endl;

    stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    cout << solution.removeStones(stones) << endl;

    stones = {{0,0}};
    cout << solution.removeStones(stones) << endl;

    stones = {{1,2},{1,3},{3,3},{3,1},{2,1},{1,0}};
    cout << solution.removeStones(stones) << endl;

    return 0;
}