/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> mem(nums.size(), {INT_MIN, INT_MIN});
        int res = INT_MIN;
        dp(nums, 0, mem, res);
        return res;
    }
private:
    pair<int, int> dp(vector<int>& nums, int index, vector<pair<int, int>>& mem, int& res){
        if(index==nums.size()-1){
            res = nums[index];
            return {nums[index], nums[index]};
        }
        if(mem[index].first!=INT_MIN && mem[index].second!=INT_MIN) return mem[index];

        auto [high, low] = dp(nums, index+1, mem, res);
        int temp1 = nums[index]*high;
        int temp2 = nums[index]*low;
        high = max(nums[index], max(temp1, temp2));
        low = min(nums[index], min(temp1, temp2));
        res = max(res, high);
        return mem[index] = {high, low};
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {2,3,-2,4};
    cout << solution.maxProduct(nums) << endl;

    nums = {-2,0,-1};
    cout << solution.maxProduct(nums) << endl;
    return 0;
}