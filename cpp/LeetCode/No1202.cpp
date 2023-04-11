/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.
*/
#include <iostream>
#include "Debug\UnionFind.h"
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(vector<int> pair : pairs){
            uf.connect(pair[0], pair[1]);
        }
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> group;
        for(int i=0;i<s.size();i++){
            group[uf.find(i)].push(s[i]);
        }
        for(int i=0;i<s.size();i++){
            s[i] = group[uf.find(i)].top();
            group[uf.find(i)].pop();
        }
        return s;
    }
};

int main(void){
    Solution solution;
    string s;
    vector<vector<int>> pairs;

    s = "dcab";
    pairs = {{0,3},{1,2}};
    cout << solution.smallestStringWithSwaps(s, pairs) << endl;

    s = "dcab";
    pairs = {{0,3},{1,2},{0,2}};
    cout << solution.smallestStringWithSwaps(s, pairs) << endl;

    s = "cba";
    pairs = {{0,1},{1,2}};
    cout << solution.smallestStringWithSwaps(s, pairs) << endl;
    return 0;
}