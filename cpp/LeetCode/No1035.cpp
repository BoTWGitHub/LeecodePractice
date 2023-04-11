/*
You are given two integer arrays nums1 and nums2. 
We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> mem(nums1.size(), vector<int>(nums2.size(), -1));
        return dp(nums1, nums2, 0, 0, mem);
    }
private:
    int dp(vector<int>& nums1, vector<int>& nums2, int i1, int i2, vector<vector<int>>& mem){
        if(i1==nums1.size() || i2==nums2.size()) return 0;
        if(mem[i1][i2]!=-1) return mem[i1][i2];

        int res = 0;
        if(nums1[i1]==nums2[i2]){
            res = dp(nums1, nums2, i1+1, i2+1, mem)+1;
        }
        else{
            res = max(dp(nums1, nums2, i1+1, i2, mem), dp(nums1, nums2, i1, i2+1, mem));
        }
        return mem[i1][i2] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = {1,4,2};
    nums2 = {1,2,4};
    cout << solution.maxUncrossedLines(nums1, nums2) << endl;

    nums1 = {2,5,1,2,5};
    nums2 = {10,5,2,1,5,2};
    cout << solution.maxUncrossedLines(nums1, nums2) << endl;

    nums1 = {1,3,7,1,7,5};
    nums2 = {1,9,2,5,1};
    cout << solution.maxUncrossedLines(nums1, nums2) << endl;
    return 0;
}