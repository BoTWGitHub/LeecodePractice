/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> mem(nums.size(), vector<int>(2, -1));
        return dp(nums, 0, false, mem);
    }
private:
    int dp(vector<int> &nums, int index, bool first, vector<vector<int>> &mem){
        if(index==nums.size()-1){
            if(first) return 0;
            else return nums[index];
        }
        if(index>=nums.size()) return 0;
        if(mem[index][first]!=-1) return mem[index][first];

        if(index==0){
            mem[index][first] = max(dp(nums, index+2, true, mem)+nums[index], dp(nums, index+1, false, mem));
        }
        else{
            mem[index][first] = max(dp(nums, index+2, first, mem)+nums[index], dp(nums, index+1, first, mem));
        }
        return mem[index][first];
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {2,3,2};
    cout << solution.rob(nums) << endl;

    nums = {1,2,3,1};
    cout << solution.rob(nums) << endl;

    nums = {1,2,3};
    cout << solution.rob(nums) << endl;

    nums = {1,3,1,3,100};
    cout << solution.rob(nums) << endl;

    return 0;
}