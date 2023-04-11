/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements 
in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/
#include <iostream>
#include <algorithm>
#include <set>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>());
        vector<int> res;
        for(int i=0;i<n;i++){
            if(n-i<res.size()) break;
            vector<int> temp = dp(nums, i, mem);
            if(temp.size()>res.size()) res = temp;
        }
        return res;
    }
private:
    vector<int> dp(vector<int>& nums, int index, vector<vector<int>>& mem){
        if(index==nums.size()) return {};
        if(!mem[index].empty()) return mem[index];

        vector<int> res = {};
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]%nums[index]==0){
                vector<int> temp = dp(nums, i, mem);
                if(temp.size()>res.size()) res = temp;
            }
        }
        res.insert(res.begin(), nums[index]);
        return mem[index] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    vector<int> res;

    nums = {1,2,3};
    res = solution.largestDivisibleSubset(nums);
    printVector(res);

    nums = {1,2,4,8};
    res = solution.largestDivisibleSubset(nums);
    printVector(res);

    nums = {1,2,7,8,14,28};
    res = solution.largestDivisibleSubset(nums);
    printVector(res);

    nums = {4,8,10,240};
    res = solution.largestDivisibleSubset(nums);
    printVector(res);
    return 0;
}