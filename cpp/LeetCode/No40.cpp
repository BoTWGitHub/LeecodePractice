/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, temp, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& temp, set<vector<int>>& res){
        if(target==0){
            res.insert(temp);
            return;
        }
        if(target<0) return;
        if(index==candidates.size()) return;

        temp.push_back(candidates[index]);
        backtrack(candidates, target-candidates[index], index+1, temp, res);
        temp.pop_back();
        while(index+1<candidates.size() && candidates[index+1]==candidates[index]) index++;
        backtrack(candidates, target, index+1, temp, res);
    }
};

int main(void){
    Solution solution;
    vector<int> candidates;
    int target;
    vector<vector<int>> res;

    candidates = {10,1,2,7,6,1,5};
    target = 8;
    res = solution.combinationSum2(candidates, target);
    print2DVector(res);

    candidates = {2,5,2,1,2};
    target = 5;
    res = solution.combinationSum2(candidates, target);
    print2DVector(res);
    return 0;
}