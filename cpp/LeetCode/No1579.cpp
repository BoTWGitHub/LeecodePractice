/*
Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi
, find the maximum number of edges you can remove so that after removing the edges
, the graph can still be fully traversed by both Alice and Bob. 
The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
*/
#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
    int getNumOfGroup(){return numOfGroup;}
private:
    vector<int> root;
    vector<int> rank;
    int numOfGroup;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        UnionFind alice(n);
        UnionFind bob(n);
        sort(edges.begin(), edges.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0]>v2[0];
        });
        for(vector<int>& edge : edges){
            int type = edge[0];
            int n1 = edge[1]-1;
            int n2 = edge[2]-1;
            if(type==1){
                if(alice.isConnected(n1, n2)) res++;
                else alice.connect(n1, n2);
            }
            else if(type==2){
                if(bob.isConnected(n1, n2)) res++;
                else bob.connect(n1, n2);
            }
            else{
                if(alice.isConnected(n1, n2) 
                    && bob.isConnected(n1, n2)) res++;
                else{
                    alice.connect(n1, n2);
                    bob.connect(n1, n2);
                }
            }
        }
        if(alice.getNumOfGroup()!=1 || bob.getNumOfGroup()!=1) return -1;
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;

    n = 4;
    edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    cout << solution.maxNumEdgesToRemove(n, edges) << endl;

    n = 4;
    edges = {{3,1,2},{3,2,3},{1,1,4},{2,1,4}};
    cout << solution.maxNumEdgesToRemove(n, edges) << endl;

    n = 4;
    edges = {{3,2,3},{1,1,2},{2,3,4}};
    cout << solution.maxNumEdgesToRemove(n, edges) << endl;
    return 0;
}