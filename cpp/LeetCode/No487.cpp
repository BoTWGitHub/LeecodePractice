/*
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        dp(nums, 0, false, 0, res);
        return res;
    }
private:
    void dp(vector<int> &nums, int index, bool flip, int count, int &res){
        if(index==nums.size() || (flip && nums[index]==0)){
            res = max(res, count);
            return;
        }

        if(nums[index]==0){
            dp(nums, index+1, true, count+1, res);
            dp(nums, index+1, flip, 0, res);
        }
        else{
            dp(nums, index+1, flip, count+1, res);
        }
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {1,0,1,1,0};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    nums = {1,0,1,1,0,1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}