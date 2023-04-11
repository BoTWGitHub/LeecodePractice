/*
Given an integer array nums sorted in non-decreasing order
, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages
, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates
, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. 
You must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while(right<nums.size()){
            if(nums[left]==nums[right]) right++;
            else nums[++left] = nums[right++];
        }
        return left+1;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int res;

    nums = {1,1,2};
    res = solution.removeDuplicates(nums);
    for(int i=0;i<res;i++) cout << nums[i] << ",";
    cout << endl;

    nums = {0,0,1,1,1,2,2,3,3,4};
    res = solution.removeDuplicates(nums);
    for(int i=0;i<res;i++) cout << nums[i] << ",";
    cout << endl;

    return 0;
}