/*
Given an integer array nums
, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int fs = INT_MAX, ss = INT_MAX;
        for(int num : nums){
            if(num<=fs){
                fs = num;
            }
            else if(num>fs && num<=ss){
                ss = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}
