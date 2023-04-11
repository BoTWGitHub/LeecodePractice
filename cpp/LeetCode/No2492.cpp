/*
You are given a positive integer n representing n cities numbered from 1 to n. 
You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road 
between cities ai and bi with a distance equal to distancei. 
The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class UnionFind{
public:
    UnionFind(int n){
        root = vector<int>(n);
        rank = vector<int>(n, 1);
        cost = vector<int>(n, INT_MAX);
        for(int i=0;i<n;i++){
            root[i] = i;
        }
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y, int c){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]){
                cost[ry] = min(c, min(cost[rx], cost[ry]));
                root[rx] = ry;
            }
            else if(rank[rx]>rank[ry]){
                cost[rx] = min(c, min(cost[rx], cost[ry]));
                root[ry] = rx;
            }
            else{
                cost[ry] = min(c, min(cost[rx], cost[ry]));
                root[rx] = ry;
            }
        }
        else{
            cost[ry] = min(c, cost[ry]);
        }
    }
    int getCost(int x){
        return cost[x];
    }
private:
    vector<int> root;
    vector<int> rank;
    vector<int> cost;
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n);
        for(vector<int>& road : roads){
            uf.connect(road[0]-1, road[1]-1, road[2]);
        }
        return uf.getCost(uf.find(n-1));
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> roads;

    n = 4;
    roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout << solution.minScore(n, roads) << endl;

    n = 4;
    roads = {{1,2,2},{1,3,4},{3,4,7}};
    cout << solution.minScore(n, roads) << endl;
    return 0;
}