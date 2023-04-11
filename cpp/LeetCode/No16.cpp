/*
Given an integer array nums of length n and an integer target
, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0]+nums[1]+nums[2];
        if(res == target) return res;
        sort(nums.begin(), nums.end());
        int diff = abs(res-target);
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1, right=nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(sum-target)<diff){
                    res = sum;
                    diff = abs(sum-target);
                }
                if(sum==target) return target;
                else if(sum>target) right--;
                else left++;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}
