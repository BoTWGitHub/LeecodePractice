/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1;j<nums.size()-2;j++){
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        vector<vector<int>> temp = twoSum(nums, j+1, target-nums[i]-nums[j]);
                        for(vector<int> v : temp){
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            res.push_back(v);
                        }
                    }
                }
            }
        }
        return res;
    }
private:
    vector<vector<int>> twoSum(vector<int> &nums, int left, int target){
        vector<vector<int>> res;
        for(int i=left;i<nums.size()-1;i++){
            if(i==left || nums[i]!=nums[i-1]){
                if(bSearch(nums, i+1, target-nums[i])){
                    res.push_back({nums[i], target-nums[i]});
                }
            }
        }
        return res;
    }
    bool bSearch(vector<int> &nums, int left, int target){
        int right = nums.size()-1;
        while(left<=right){
            int mid = (right-left)+left;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int target;
    vector<vector<int>> res;

    nums = {1,0,-1,0,-2,2};
    target = 0;
    res = solution.fourSum(nums, target);
    print2DVector(res);

    nums = {2,2,2,2,2};
    target = 8;
    res = solution.fourSum(nums, target);
    print2DVector(res);
    return 0;
}