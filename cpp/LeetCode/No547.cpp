/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
#include <iostream>
#include "Debug\VectorDebug.h"

using namespace std;

class UnionFind{
public:
    UnionFind(int size){
        root = vector<int>(size, 0);
        rank = vector<int>(size, 1);
        for(int i=0;i<size;i++){
            root[i] = i;
        }
        numOfGroup = size;
    }
    int find(int x){
        if(x==root[x]) return x;
        return root[x] = find(root[x]);        
    }
    void connect(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if(rank[rootY]<rank[rootX]){
                root[rootY] = rootX;
            }
            else if(rank[rootY]>rank[rootX]){
                root[rootX] = rootY;
            }
            else{
                root[rootY] = rootX;
                rank[rootX]++;
            }
            numOfGroup--;
        }
    }
    bool isConnected(int x, int y){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected[0].size();j++){
                if(isConnected[i][j]) uf.connect(i, j);
            }
        }
        return uf.getNumOfGroup();
    }
};

int main(){
    Solution solution;

    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    cout << solution.findCircleNum(isConnected) << endl;
    return 0;
}
