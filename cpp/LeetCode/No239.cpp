/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.
*/
#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        
        for(int i=0;i<k;i++){
            if(q.empty()||nums[i]<nums[q.back()]){
                q.push_back(i);
            }
            else{
                while(!q.empty() && nums[i]>=nums[q.back()]) q.pop_back();
                q.push_back(i);
            }
        }
        res.push_back(nums[q.front()]);

        for(int i=k;i<nums.size();i++){
            while(!q.empty() && i-q.front()>=k) q.pop_front();
            while(!q.empty() && nums[i]>=nums[q.back()]) q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;
    vector<int> res;

    nums = {1,3,-1,-3,5,3,6,7};
    k = 3;
    res = solution.maxSlidingWindow(nums, k);
    printVector(res);

    nums = {1};
    k = 1;
    res = solution.maxSlidingWindow(nums, k);
    printVector(res);
    return 0;
}