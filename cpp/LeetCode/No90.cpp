/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        int len = 0;
        for(int i=0;i<=nums.size();i++){
            backtrack(nums, len, 0, temp, res);
            len++;
        }
        return res;
    }
private:
    void backtrack(vector<int>& nums, int& len, int index, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size()==len){
            res.push_back(temp);
            return;
        }

        int last = -1;
        int i = index;
        while(i<nums.size()){
            if(last!=-1){
                while(i<nums.size() && nums[i]==nums[last]) i++;
                if(i==nums.size()) break;
            }
            temp.push_back(nums[i]);
            backtrack(nums, len, i+1, temp, res);
            temp.pop_back();
            last = i;
        }
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    vector<vector<int>> res;

    nums = {1,2,2};
    res = solution.subsetsWithDup(nums);
    print2DVector(res);

    nums = {0};
    res = solution.subsetsWithDup(nums);
    print2DVector(res);

    nums = {1,2,2,3};
    res = solution.subsetsWithDup(nums);
    print2DVector(res);
    return 0;
}