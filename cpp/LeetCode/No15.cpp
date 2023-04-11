/*
Given an integer array nums
, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i==0 || nums[i]!=nums[i-1]){
                twoSum(nums, i, res);
            }
        }
        return res;
    }
private:
    void twoSum(vector<int> &nums, int i, vector<vector<int>> &res){
        int left=i+1, right=nums.size()-1;
        int target = -(nums[i]);
        while(left<right){
            int temp = nums[left]+nums[right];
            if(temp==target){
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
            }
            else if(temp>target) right--;
            else left++;
        }
    }
};

int main(){
    Solution solution;

    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = solution.threeSum(nums);
    print2DVector(res);
    return 0;
}
