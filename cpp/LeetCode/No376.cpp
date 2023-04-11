/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 1;
        int down = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up = down+1;
            }
            else if(nums[i]<nums[i-1]){
                down = up+1;
            }
        }
        return max(up, down);
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,7,4,9,2,5};
    cout << solution.wiggleMaxLength(nums) << endl;

    nums = {1,17,5,10,13,15,10,5,16,8};
    cout << solution.wiggleMaxLength(nums) << endl;

    nums = {1,2,3,4,5,6,7,8,9};
    cout << solution.wiggleMaxLength(nums) << endl;

    nums = {33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
    cout << solution.wiggleMaxLength(nums) << endl;
    return 0;
}