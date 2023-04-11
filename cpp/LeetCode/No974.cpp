/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        vector<int> prefix(n, 0);
        for(int i=0;i<n;i++){
            if(i==0) prefix[i] = nums[i];
            else prefix[i] = prefix[i-1]+nums[i];
            m[prefix[i]%k].push_back(i);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            int target = prefix[i]%k;
            if(target==0) res++;
            for(int j : m[target]){
                if(j<i) res++;
                else break;
            }
            int temp = target>0?target-k:target+k;
            if(m.count(temp)){
                for(int j : m[temp]){
                    if(j<i) res++;
                    else break;
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;

    nums = {4,5,0,-2,-3,1};
    k = 5;
    cout << solution.subarraysDivByK(nums, k) << endl;

    nums = {5};
    k = 9;
    cout << solution.subarraysDivByK(nums, k) << endl;

    nums = {7,-5,5,-8,-6,6,-4,7,-8,-7};
    k = 7;
    cout << solution.subarraysDivByK(nums, k) << endl;
    return 0;
}