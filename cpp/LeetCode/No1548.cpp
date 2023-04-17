/*
We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. 
Each city has a name consisting of exactly three upper-case English letters given in the string array names. 
Starting at any city x, you can reach any city y where y != x (i.e., the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. 
You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance. 
The path should be of the same length of targetPath and should be valid (i.e., there should be a direct road between ans[i] and ans[i + 1]). 
If there are multiple answers return any one of them.

The edit distance is defined as follows:

define editDistance(targetPath, myPath) {
    dis := 0
    a := targetPath.length
    b := myPath.length
    if a != b {
        return 1000000000
    }
    for (i := 0; i < a; i += 1) {
        if targetPath[i] != myPath[i] {
            dis += 1
        }
    }
}

*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> roads;
    vector<string> names;
    vector<string> targetPath;
    vector<int> res;

    n = 5;
    roads = {{0,2},{0,3},{1,2},{1,3},{1,4},{2,4}};
    names = {"ATL","PEK","LAX","DXB","HND"};
    targetPath = {"ATL","DXB","HND","LAX"};
    res = solution.mostSimilar(n, roads, names, targetPath);
    printVector(res);

    n = 4;
    roads = {{1,0},{2,0},{3,0},{2,1},{3,1},{3,2}};
    names = {"ATL","PEK","LAX","DXB"};
    targetPath = {"ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"};
    res = solution.mostSimilar(n, roads, names, targetPath);
    printVector(res);

    n = 6;
    roads = {{0,1},{1,2},{2,3},{3,4},{4,5}};
    names = {"ATL","PEK","LAX","ATL","DXB","HND"};
    targetPath = {"ATL","DXB","HND","DXB","ATL","LAX","PEK"};
    res = solution.mostSimilar(n, roads, names, targetPath);
    printVector(res);
    return 0;
}