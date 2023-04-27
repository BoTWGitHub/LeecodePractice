/*
You are given two non-increasing 0-indexed integer arrays nums1?????? and nums2??????.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. 
The distance of the pair is j - i????.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int res = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums2.size()-i-1<=res) break;
            if(i==nums2.size()) break;
            int left = i, right = nums2.size()-1;
            while(left<right){
                int mid = (right-left+1)/2+left;
                if(nums2[mid]>=nums1[i]) left = mid;
                else right = mid-1;
            }
            if(nums2[left]>=nums1[i]) res = std::max(res, left-i);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> nums1;
    std::vector<int> nums2;

    nums1 = {55,30,5,4,2};
    nums2 = {100,20,10,10,5};
    std::cout << solution.maxDistance(nums1, nums2) << std::endl;

    nums1 = {2,2,2};
    nums2 = {10,10,1};
    std::cout << solution.maxDistance(nums1, nums2) << std::endl;

    nums1 = {30,29,19,5};
    nums2 = {25,25,25,25,25};
    std::cout << solution.maxDistance(nums1, nums2) << std::endl;

    nums1 = {30,29,19,5};
    nums2 = {70,70};
    std::cout << solution.maxDistance(nums1, nums2) << std::endl;
    return 0;
}