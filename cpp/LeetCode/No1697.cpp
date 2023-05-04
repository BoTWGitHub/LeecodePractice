/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. 
Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj]
, your task is to determine for each queries[j] whether there is a path between pj and qj 
such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true 
if there is a path for queries[j] is true, and false otherwise.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"

class Solution {
public:
    std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList, std::vector<std::vector<int>>& queries) {
        root = std::vector<int>(n);
        rank = std::vector<int>(n, 1);
        for(int i=0;i<n;i++){
            root[i] = i;
        }
        
        auto cmp = [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[2]<v2[2];
        };

        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        std::sort(edgeList.begin(), edgeList.end(), cmp);
        std::sort(queries.begin(), queries.end(), cmp);
        std::vector<bool> res(queries.size());

        int edgeIndex = 0;
        for(int i=0;i<queries.size();i++){
            for(int j=edgeIndex;j<edgeList.size();j++){
                if(edgeList[j][2]>=queries[i][2]){
                    edgeIndex = j;
                    break;
                }
                else{
                    connect(edgeList[j][0], edgeList[j][1]);
                }
            }
            res[queries[i][3]] = isConnected(queries[i][0], queries[i][1]);
        }
        return res;
    }
private:
    std::vector<int> root;
    std::vector<int> rank;
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
        }
    }
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
};

int main(void){
    Solution solution;
    int n;
    std::vector<std::vector<int>> edgeList;
    std::vector<std::vector<int>> queries;
    std::vector<bool> res;

    n = 3;
    edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    queries = {{0,1,2},{0,2,5}};
    res = solution.distanceLimitedPathsExist(n, edgeList, queries);
    printVector(res);

    n = 5;
    edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    queries = {{0,4,14},{1,4,13}};
    res = solution.distanceLimitedPathsExist(n, edgeList, queries);
    printVector(res);
    return 0;
}