/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. 
The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ajList(n);
        for(int i=1;i<n;i++) ajList[parent[i]].push_back(i);
        int res = 0;
        dfs(0, ajList, s, res);
        return res;
    }
private:
    int dfs(int node, vector<vector<int>>& ajList, string& s, int& ans){
        int first = 1;
        int second = 1;
        for(int neighbor : ajList[node]){
            int temp = dfs(neighbor, ajList, s, ans)+1;
            if(s[neighbor]==s[node]) continue;
            if(temp>first){
                second = first;
                first = temp;
            }
            else if(temp>second){
                second = temp;
            }
        }
        ans = max(ans, first+second-1);
        return first;
    }
};

int main(void){
    Solution solution;
    vector<int> parent;
    string s;

    parent = {-1,0,0,1,1,2};
    s = "abacbe";
    cout << solution.longestPath(parent, s) << endl;

    parent = {-1,0,0,0};
    s = "aabc";
    cout << solution.longestPath(parent, s) << endl;

    parent = {-1,0,1};
    s = "aab";
    cout << solution.longestPath(parent, s) << endl;
    return 0;
}