/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {  //top-down DP
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> mem(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            res = max(res, dp(nums, i, mem));
        }
        return res;
    }
private:
    int dp(vector<int> &nums, int index, vector<int> &mem){
        if(mem[index]!=0){
            return mem[index];
        }
        if(index == nums.size()-1){
            mem[index] = 1;
            return mem[index];
        }
        int res = 1;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>nums[index]){
                res = max(res, dp(nums, i, mem)+1);
            }
        }
        mem[index] = res;
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub = {nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i]>sub.back()){
                sub.push_back(nums[i]);
            }
            else{
                int left=0, right=sub.size()-1;
                while(left<right){
                    int mid = (right-left)/2+left;
                    if(sub[mid]>=nums[i]) right = mid;
                    else left = mid+1;
                }
                sub[left]=nums[i];
            }
        }
        return sub.size();
    }
};

int main(){
    Solution2 solution;

    vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    cout << solution.lengthOfLIS(nums) << endl;

    nums = {0,1,0,3,2,3};
    cout << solution.lengthOfLIS(nums) << endl;

    nums = {7,7,7,7,7,7,7};
    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}
