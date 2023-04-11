/*
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int num : nums) s+=num;
        if(s%2==1) return false;
        int target = s/2;
        vector<vector<bool>> mem(nums.size(), vector<bool>(target+1, true));
        return dp(nums, 0, target, mem);
    }
private:
    bool dp(vector<int>& nums, int index, int target, vector<vector<bool>>& mem){
        if(target<0) return false;
        if(target==0) return true;
        if(index==nums.size()) return false;
        if(!mem[index][target]) return mem[index][target];

        if(dp(nums, index+1, target-nums[index], mem)) return mem[index][target] = true;
        else return mem[index][target] = dp(nums, index+1, target, mem);
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,5,11,5};
    cout << solution.canPartition(nums) << endl;

    nums = {1,2,3,5};
    cout << solution.canPartition(nums) << endl;

    nums = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
    cout << solution.canPartition(nums) << endl;
    return 0;
}