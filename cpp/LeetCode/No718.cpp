/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> indexMap;
        for(int i=0;i<nums2.size();i++){
            indexMap[nums2[i]].push_back(i);
        }
        vector<vector<int>> mem(nums1.size(), vector<int>(nums2.size(), -1));
        int res = 0;
        for(int i=0;i<nums1.size();i++){
            if(indexMap.count(nums1[i])>0){
                for(int index : indexMap[nums1[i]]){
                    res = max(res, dp(nums1, nums2, i, index, mem));
                }
            }
        }
        return res;
    }
private:
    int dp(vector<int>& nums1, vector<int>& nums2, int index1, int index2, vector<vector<int>> &mem){
        if(index1==nums1.size() || index2==nums2.size() || nums1[index1]!=nums2[index2]) return 0;
        if(mem[index1][index2]!=-1) return mem[index1][index2];
        
        return mem[index1][index2] = dp(nums1, nums2, index1+1, index2+1, mem) + 1;
    }
};

int main(void){
    Solution solution;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = {1,2,3,2,1};
    nums2 = {3,2,1,4,7};
    cout << solution.findLength(nums1, nums2) << endl;

    nums1 = {0,0,0,0,0};
    nums2 = {0,0,0,0,0};
    cout << solution.findLength(nums1, nums2) << endl;

    return 0;
}