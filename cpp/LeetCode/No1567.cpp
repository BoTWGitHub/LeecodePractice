/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]>0){
                pos++;
                neg = neg==0?0:neg+1;
             }
             else if(nums[i]<0){
                int temp = pos+1;
                pos = neg==0?0:neg+1;
                neg = temp;
             }
             else{
                pos = 0;
                neg = 0;
             }
             res = max(res, pos);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,-2,-3,4};
    cout << solution.getMaxLen(nums) << endl;

    nums = {0,1,-2,-3,-4};
    cout << solution.getMaxLen(nums) << endl;

    nums = {-1,-2,-3,0,1};
    cout << solution.getMaxLen(nums) << endl;
    return 0;
}