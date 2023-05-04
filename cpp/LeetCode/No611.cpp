/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        if(nums.size()<3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int left = j+1, right = nums.size()-1;
                int target = nums[i]+nums[j];
                while(left<right){
                    int mid = (right-left+1)/2+left;
                    if(nums[mid]>=target) right = mid-1;
                    else left = mid;
                }
                if(nums[left]<target) res+=left-j;
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> nums;

    nums = {2,2,3,4};
    std::cout << solution.triangleNumber(nums) << std::endl;

    nums = {4,2,3,4};
    std::cout << solution.triangleNumber(nums) << std::endl;

    nums = {0};
    std::cout << solution.triangleNumber(nums) << std::endl;
    return 0;
}