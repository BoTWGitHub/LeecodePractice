/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mem;
        int maxNum = nums[0], minNum = nums[0];
        for(int num : nums){
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
            mem[num]+=num;
        }
        vector<int> dp(maxNum-minNum+1);
        if(dp.size()<2) return mem[minNum];
        dp[0] = mem[minNum];
        dp[1] = max(dp[0], mem[minNum+1]);
        for(int i=2;i<dp.size();i++){
            dp[i] = max(dp[i-2]+mem[i+minNum], dp[i-1]);
        }
        return dp.back();
    }
};

int main(){
    Solution solution;

    vector<int> nums = {2,2,3,3,3,4};
    cout << solution.deleteAndEarn(nums) << endl;
    return 0;
}
