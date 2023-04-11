/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order
, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int left = 0, right = nums.size()-1;
        while(left<right && temp[left]==nums[left]) left++;
        while(left<right && temp[right]==nums[right]) right--;
        if(left==right) return 0;
        return right-left+1;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {2,6,4,8,10,9,15};
    cout << solution.findUnsortedSubarray(nums) << endl;

    nums = {1,2,3,4};
    cout << solution.findUnsortedSubarray(nums) << endl;
    return 0;
}