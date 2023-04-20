/*
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries
, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer
, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> res(n);
        for(int i=0;i<n;i++){
            vector<int> sub(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(sub.begin(), sub.end());
            int diff = sub[1]-sub[0];
            bool arthmetic = true;
            for(int i=2;i<sub.size();i++){
                if(sub[i]-sub[i-1]!=diff){
                    arthmetic = false;
                    break;
                }
            }
            res[i] = arthmetic;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    vector<int> l;
    vector<int> r;
    vector<bool> res;

    nums = {4,6,5,9,3,7};
    l = {0,0,2};
    r = {2,3,5};
    res = solution.checkArithmeticSubarrays(nums, l, r);
    printVector(res);

    nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    l = {0,1,6,4,8,7};
    r = {4,4,9,7,9,10};
    res = solution.checkArithmeticSubarrays(nums, l, r);
    printVector(res);

    nums = {-3,-6,-8,-4,-2,-8,-6,0,0,0,0};
    l = {5,4,3,2,4,7,6,1,7};
    r = {6,5,6,3,7,10,7,4,10};
    res = solution.checkArithmeticSubarrays(nums, l, r);
    printVector(res);
    return 0;
}