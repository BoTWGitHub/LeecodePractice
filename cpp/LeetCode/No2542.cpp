/*
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. 
You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Debug\VectorDebug.h"

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        long long res = 0;
        int n = nums1.size();
        std::vector<std::pair<int, int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        std::sort(nums.begin(), nums.end(), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2){
            return p1.first>p2.first;
        });
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        long long tempSum = 0;
        for(int i=0;i<k;i++){
            tempSum+=nums[i].second;
            heap.push(nums[i].second);
        }
        res = tempSum*nums[k-1].first;
        for(int i=k;i<n;i++){
            tempSum+=nums[i].second-heap.top();
            heap.pop();
            heap.push(nums[i].second);
            res = std::max(res, tempSum*nums[i].first);
        }

        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> nums1;
    std::vector<int> nums2;
    int k;

    nums1 = {1,3,3,2};
    nums2 = {2,1,3,4};
    k = 3;
    std::cout << solution.maxScore(nums1, nums2, k) << std::endl;

    nums1 = {4,2,3,1,1};
    nums2 = {7,5,10,9,6};
    k = 1;
    std::cout << solution.maxScore(nums1, nums2, k) << std::endl;
    return 0;
}