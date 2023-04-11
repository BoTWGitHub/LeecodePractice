/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed
, the only constraint stopping you from robbing each of them is 
that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house
, return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return dp(nums, 0, mem);
    }
private:
    int dp(vector<int> &nums, int index, vector<int> &mem){
        if(index>=nums.size()) return 0;
        if(mem[index]!=-1) return mem[index];

        int res = max(nums[index] + dp(nums, index+2, mem), dp(nums, index+1, mem));
        mem[index] = res;
        return res;
    }
};

int main(){
    Solution solution;

    vector<int> nums;

    nums = {1,2,3,1};
    cout << solution.rob(nums) << endl;

    nums = {2,7,9,3,1};
    cout << solution.rob(nums) << endl;

    return 0;
}
