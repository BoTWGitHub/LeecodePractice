/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array.
That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> heap;
        heap.push({nums.back(), nums.size()-1});
        vector<int> dp(nums.size());
        dp.back() = nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            pair<int, int> p = heap.top();
            while(p.second-i>k){
                heap.pop();
                p = heap.top();
            }
            dp[i] = nums[i]+p.first;
            heap.push({dp[i], i});
        }
        return dp[0];
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;

    nums = {1,-1,-2,4,-7,3};
    k = 2;
    cout << solution.maxResult(nums, k) << endl;

    nums = {10,-5,-2,4,0,3};
    k = 17;
    cout << solution.maxResult(nums, k) << endl;

    nums = {1,-5,-20,4,-1,3,-6,-3};
    k = 2;
    cout << solution.maxResult(nums, k) << endl;
    return 0;
}