/*
You are given an integer array nums. You must perform exactly one operation where you can replace one element nums[i] with nums[i] * nums[i]. 

Return the maximum possible subarray sum after exactly one operation. The subarray must be non-empty.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        vector<vector<int>> mem(nums.size(), vector<int>(2, INT_MIN));
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res = max(res, dp(nums, i, false, mem));
        }
        return res;
    }
private:
    int dp(vector<int>& nums, int index, bool ops, vector<vector<int>>& mem){
        if(index==nums.size()) return 0;
        if(mem[index][ops]!=INT_MIN) return mem[index][ops];

        int res = 0;

        if(ops){
            res = max(nums[index], dp(nums, index+1, ops, mem)+nums[index]);
        }
        else{
            int op = max(nums[index]*nums[index], dp(nums, index+1, true, mem)+nums[index]*nums[index]);
            int nop = max(nums[index], dp(nums, index+1, ops, mem)+nums[index]);
            res = max(op, nop);
        }

        return mem[index][ops] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {2,-1,-4,-3};
    cout << solution.maxSumAfterOperation(nums) << endl;

    nums = {1,-1,1,1,-1,-1,1};
    cout << solution.maxSumAfterOperation(nums) << endl;

    nums = {29,71,-52,-23,-28,50,27,29,0,50,-92,22,-38,90,3,6,70,-56,-7,40,79,98,72,88,-5,-78,12,69,30,-73,99,-59,33,0,-6,25,87,-93,20,-89,-22,80,57,51,48,0,65,-57,-57,28,-42,-97,97,-49,38,40,-41,3,31,-12,47,-10,17,-32,68,40,55,86,-99,-2,100,89,31,-67};
    cout << solution.maxSumAfterOperation(nums) << endl;
    return 0;
}