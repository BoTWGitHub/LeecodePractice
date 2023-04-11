/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> mem(target+1, -1);
        return dp(nums, target, mem);
    }
private:
    int dp(vector<int>& nums, int target, vector<int>& mem){
        if(target==0) return 1;
        else if(target<0) return 0;
        if(mem[target]!=-1) return mem[target];

        int res = 0;
        for(int num : nums){
            if(num<=target) res+=dp(nums, target-num, mem);
        }
        return mem[target] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int target;

    nums = {1,2,3};
    target = 4;
    cout << solution.combinationSum4(nums, target) << endl;

    nums = {9};
    target = 3;
    cout << solution.combinationSum4(nums, target) << endl;
    return 0;
}