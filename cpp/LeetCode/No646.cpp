/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int res = 1;
        int last = pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>last){
                res++;
                last = pairs[i][1];
            }
            else{
                last = min(last, pairs[i][1]);
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> pairs;

    pairs = {{1,2},{2,3},{3,4}};
    cout << solution.findLongestChain(pairs) << endl;

    pairs = {{1,2},{7,8},{4,5}};
    cout << solution.findLongestChain(pairs) << endl;
    return 0;
}