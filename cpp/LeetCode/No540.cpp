/*
You are given a sorted array consisting of only integers where every element appears exactly twice
, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=(right-left)/2+left;
            if(mid%2==1) mid--;
            if(nums[mid]==nums[mid+1]) left=mid+2;
            else right=mid;
        }
        return nums[left];
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums) << endl;

    nums = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums) << endl;

    return 0;
}