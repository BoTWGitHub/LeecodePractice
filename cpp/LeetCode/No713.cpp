/*
Given an array of integers nums and an integer k
, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int product = 1;
        int res = 0;
        for(int right=0;right<nums.size();right++){
            product*=nums[right];
            while(product>=k && left<=right) product/=nums[left++];
            res+=(right++-left+1);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;

    nums = {10,5,2,6};
    k = 100;
    cout << solution.numSubarrayProductLessThanK(nums, k) << endl;

    nums = {1,2,3};
    k = 0;
    cout << solution.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}