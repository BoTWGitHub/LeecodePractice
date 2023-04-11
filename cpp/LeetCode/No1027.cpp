/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<unordered_map<int, int>>> mem(nums.size(), vector<unordered_map<int, int>>(nums.size()));
        return dp(nums, 0, -1, 1000, mem);
    }
private:
    int dp(vector<int>& nums, int index, int last, int diff, vector<vector<unordered_map<int, int>>>& mem){
        if(index==nums.size()) return 0;
        if(last!=-1 && mem[index][last].count(diff)) return mem[index][last][diff];

        int res = 0;
        if(last==-1){
            res = max(dp(nums, index+1, index, diff, mem)+1, dp(nums, index+1, last, diff, mem));
        }
        else{
            if(diff!=1000){
                if(nums[index]-nums[last]==diff) res = dp(nums, index+1, index, diff, mem)+1;
                else res = dp(nums, index+1, last, diff, mem);
            }
            else{
                res = max(dp(nums, index+1, index, nums[index]-nums[last], mem)+1, dp(nums, index+1, last, diff, mem));
            }
        }
        if(last!=-1) mem[index][last][diff] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {3,6,9,12};
    cout << solution.longestArithSeqLength(nums) << endl;

    nums = {9,4,7,2,10};
    cout << solution.longestArithSeqLength(nums) << endl;

    nums = {20,1,15,3,10,5,8};
    cout << solution.longestArithSeqLength(nums) << endl;

    nums = {0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,0,1,1,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,1,0,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,0,1,1,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,1,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,0};
    cout << solution.longestArithSeqLength(nums) << endl;
    return 0;
}