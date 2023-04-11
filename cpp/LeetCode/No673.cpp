/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> mem(nums.size(), {1, 1});
        int maxLen = 1;
        for(int i=0;i<nums.size();i++){
            maxLen = max(maxLen, dp(nums, i, mem).first);
        }
        int res = 0;
        for(auto& [len, cnt] : mem){
            if(len==maxLen){
                res+=cnt;
            }
        }
        return res;
    }
private:
    pair<int, int> dp(vector<int>& nums, int index, vector<pair<int, int>>& mem){
        if(index==0) return {1,1};
        if(mem[index].first!=1 || mem[index].second!=1) return mem[index];

        int len = 1, cnt = 1;
        for(int i=0;i<index;i++){
            if(nums[i]<nums[index]){
                pair<int, int> temp = dp(nums, i, mem);
                if(temp.first+1>len){
                    len = temp.first+1;
                    cnt = temp.second;
                }
                else if(temp.first+1==len){
                    cnt+=temp.second;
                }
            }
        }
        return mem[index] = {len, cnt};
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,3,5,4,7};
    cout << solution.findNumberOfLIS(nums) << endl;

    nums = {2,2,2,2,2};
    cout << solution.findNumberOfLIS(nums) << endl;
    return 0;
}