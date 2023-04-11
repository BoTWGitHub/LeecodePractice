/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi
, return true if it is possible to split everyone into two groups in this way.
*/
#include <iostream>
#include <vector>
#include "Debug\UnionFind.h"
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> ajList(n);
        for(vector<int>& dislike : dislikes){
            ajList[dislike[0]-1].push_back(dislike[1]-1);
            ajList[dislike[1]-1].push_back(dislike[0]-1);
        }
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            for(int neighbor : ajList[i]){
                if(uf.isConnected(i, neighbor)) return false;
                uf.connect(neighbor, ajList[i][0]);
            }
        }
        return true;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> dislikes;

    n = 4;
    dislikes = {{1,2},{1,3},{2,4}};
    cout << solution.possibleBipartition(n, dislikes) << endl; //true

    n = 3;
    dislikes = {{1,2},{1,3},{2,3}};
    cout << solution.possibleBipartition(n, dislikes) << endl; //false

    n = 5;
    dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    cout << solution.possibleBipartition(n, dislikes) << endl; //false
    return 0;
}