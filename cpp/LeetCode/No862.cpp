/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.

A subarray is a contiguous part of an array.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0;i<n;i++) prefix[i+1] = prefix[i]+nums[i];
        deque<int> q;
        for(int i=0;i<n+1;i++){
            while(!q.empty() && prefix[i]<=prefix[q.back()]) q.pop_back();
            while(!q.empty() && prefix[i]-prefix[q.front()]>=k){
                int left = q.front();
                q.pop_front();
                res = min(res, i-left);
            }
            q.push_back(i);
        }
        return res==INT_MAX?-1:res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;

    nums = {1};
    k = 1;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {1,2};
    k = 4;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {2,-1,2};
    k = 3;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {84,-37,32,40,95};
    k = 167;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {56,-21,56,35,-9};
    k = 61;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {-28,81,-20,28,-29};
    k = 89;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {17,85,93,-45,-21};
    k = 150;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {75,-32,50,32,97};
    k = 129;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6};
    k = 151;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {-22,73,-28,62,4,-21,-39,-21,-26,47,79,64,15,86,-20,-7,-24,-5,21,73};
    k = 87;
    cout << solution.shortestSubarray(nums, k) << endl;

    nums = {17985,-36292,-23941,80618,20594,-6181,9181,65796,-25716,66593,-6873,34062,29878,852,-4767,-36415,11783,8085,-41063,-39940,74284,66272,82385,51634,-48550,9028,-30777,86509,44623,9413,-38369,-1822,46408,35217,72635,-16560,85373,52105,39477,3852,45974,-21593,15481,47280,73889,-42981,54978,95169,-19615,93133};
    k = 387303;
    cout << solution.shortestSubarray(nums, k) << endl;
    return 0;
}