/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size()+1;
        int s = 0;
        int left = 0, right = 0;
        while(right<nums.size()){
            s+=nums[right];
            while(s>=target){
                res = min(res, right-left+1);
                s-=nums[left++];
            }
            right++;
        }
        return res<nums.size()+1?res:0;
    }
};

int main(void){
    Solution solution;
    int target;
    vector<int> nums;

    /*target = 7;
    nums = {2,3,1,2,4,3};
    cout << solution.minSubArrayLen(target, nums) << endl;

    target = 4;
    nums = {1,4,4};
    cout << solution.minSubArrayLen(target, nums) << endl;

    target = 11;
    nums = {1,1,1,1,1,1,1,1};
    cout << solution.minSubArrayLen(target, nums) << endl;*/

    target = 11;
    nums = {1,2,3,4,5};
    cout << solution.minSubArrayLen(target, nums) << endl;
    return 0;
}