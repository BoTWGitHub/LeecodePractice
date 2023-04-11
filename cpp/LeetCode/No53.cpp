/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> mem(nums.size(), INT_MIN);
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            res = max(res, dp(nums, i, mem));
        }
        return res;
    }
private:
    int dp(vector<int>& nums, int index, vector<int> &mem){
        if(index==nums.size()) return 0;
        if(mem[index]!=INT_MIN) return mem[index];

        int res = max(nums[index], nums[index]+dp(nums, index+1, mem));
        return mem[index] = res;
    }
};

int main(void){
    Solution solution;

    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(nums) << endl;

    nums = {1};
    cout << solution.maxSubArray(nums) << endl;

    nums = {5,4,-1,7,8};
    cout << solution.maxSubArray(nums) << endl;

    return 0;
}