/*
You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
Remove x from nums.
Return the maximum score after performing m operations.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution { //top-down
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        vector<vector<int>> mem(m, vector<int>(m, INT_MAX));
        return dp(0, 0, mem, nums, multipliers);
    }
private:
    int n;
    int m;
    int dp(int i, int left, vector<vector<int>> &mem, vector<int> &nums, vector<int> &multi){
        if(i==m) return 0;
        if(mem[i][left]==INT_MAX){
            int l = nums[left]*multi[i] + dp(i+1, left+1, mem, nums, multi);
            int r = nums[n-1-i+left]*multi[i] + dp(i+1, left, mem, nums, multi);
            mem[i][left] = max(l, r);
        }
        return mem[i][left];
    }
};

class Solution2 { //buttom-up
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i=m-1;i>=0;i--){
            for(int left=i;left>=0;left--){
                dp[i][left] = max(nums[left]*multipliers[i] + dp[i+1][left+1], 
                                  nums[n-1-i+left]*multipliers[i] + dp[i+1][left]);
            }
        }
        return dp[0][0];
    }
};

int main(void){
    Solution2 solution;

    vector<int> nums = {-5,-3,-3,-2,7,1};
    vector<int> multi = {-10,-5,3,4,6};
    cout << solution.maximumScore(nums, multi) << endl;
    return 0;
}