/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        RadixSort(nums);
        int res = 0;
        for(int i=1;i<nums.size();i++){
            res = max(res, nums[i]-nums[i-1]);
        }
        return res;
    }
private:
    void RadixSort(vector<int>& nums){
        int maxNum = *max_element(nums.begin(), nums.end());
        int divider = 1;
        int radix = 10;
        vector<int> aux(nums.size());
        while(maxNum/divider>0){
            vector<int> count(radix, 0);
            for(int i=0;i<nums.size();i++){
                count[(nums[i]/divider)%10]++;
            }
            for(int i=1;i<count.size();i++){
                count[i]+=count[i-1];
            }
            for(int i=nums.size()-1;i>=0;i--){
                aux[--count[(nums[i]/divider)%10]] = nums[i];
            }
            for(int i=0;i<nums.size();i++){
                nums[i] = aux[i];
            }
            divider*=10;
        }
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {3,6,9,1};
    cout << solution.maximumGap(nums) << endl;

    nums = {10};
    cout << solution.maximumGap(nums) << endl;

    nums = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    cout << solution.maximumGap(nums) << endl;
    return 0;
}