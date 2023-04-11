/*
Given an array of distinct integers candidates and a target integer target
, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, temp, res);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int& target, int index, vector<int>& temp, vector<vector<int>>& res){
        if(target==0){
            res.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                target-=candidates[i];
                backtrack(candidates, target, i, temp, res);
                temp.pop_back();
                target+=candidates[i];
            }
            else break;
        }
    }
};

int main(void){
    Solution solution;
    vector<int> candidates;
    int target;
    vector<vector<int>> res;

    candidates = {2,3,6,7};
    target = 7;
    res = solution.combinationSum(candidates, target);
    print2DVector(res);

    candidates = {2,3,5};
    target = 8;
    res = solution.combinationSum(candidates, target);
    print2DVector(res);

    candidates = {2};
    target = 1;
    res = solution.combinationSum(candidates, target);
    print2DVector(res);
    return 0;
}