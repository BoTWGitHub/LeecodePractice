/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mem;
        mem[0]=0;
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(mem.count(s%k)==0){
                mem[s%k]=i+1;
            }
            else if(mem[s%k]<i){
                return true;
            }
        }
        return false;
    }
};

int main(void){
    Solution solution;

    vector<int> nums;
    int k;

    nums = {23,2,4,6,7};
    k = 6;
    cout << solution.checkSubarraySum(nums, k) << endl;

    nums = {23,2,6,4,7};
    k = 6;
    cout << solution.checkSubarraySum(nums, k) << endl;

    nums = {23,2,6,4,7};
    k = 13;
    cout << solution.checkSubarraySum(nums, k) << endl;

    return 0;
}