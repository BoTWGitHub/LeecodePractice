/*
Given an array nums of n integers where nums[i] is in the range [1, n]
, return an array of all the integers in the range [1, n] that do not appear in nums.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> map(nums.size()+1);
        for(int num : nums){
            map[num]++;
        }
        for(int i=1;i<nums.size()+1;i++){
            if(map[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(void){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution solution;
    vector<int> res = solution.findDisappearedNumbers(nums);

    for(int num : res){
        cout << num << ",";
    }
    cout << endl;

    return 0;
}