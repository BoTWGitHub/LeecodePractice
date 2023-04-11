/*
If the depth of a tree is smaller than 5, then this tree can be represented by an array of three-digit integers. 
For each integer in this array:

The hundreds digit represents the depth d of this node where 1 <= d <= 4.
The tens digit represents the position p of this node in the level it belongs to where 1 <= p <= 8. The position is the same as that in a full binary tree.
The units digit represents the value v of this node where 0 <= v <= 9.
Given an array of ascending three-digit integers nums representing a binary tree with a depth smaller than 5, return the sum of all paths from the root towards the leaves.

It is guaranteed that the given array represents a valid connected binary tree.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<int> tree(15, -1);
        for(int num : nums){
            int d = num/100-1; //0~3
            int p = num/10%10-1; //0~7
            int index = pow(2, d) + p - 1;
            tree[index] = num%10;
        }
        int last = 0;
        for(int d=0;d<3;d++){
            for(int i=0;i<pow(2, d);i++){
                int index = last+i;
                if(tree[index]==-1) continue;
                int left = index*2+1, right = index*2+2;
                if(tree[left]==-1 && tree[right]==-1) tree[right]=tree[index];
                else{
                    if(tree[left]!=-1) tree[left]+=tree[index];
                    if(tree[right]!=-1) tree[right]+=tree[index];
                }
            }
            last+=pow(2, d);
        }
        int res = 0;
        for(int i=last;i<15;i++){
            if(tree[i]!=-1) res+=tree[i];
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;

    nums = {113,215,221};
    cout << solution.pathSum(nums) << endl;

    nums = {113,221};
    cout << solution.pathSum(nums) << endl;

    nums = {115,215,224,325,336,446,458};
    cout << solution.pathSum(nums) << endl;

    nums = {113,229,349,470,485};
    cout << solution.pathSum(nums) << endl;
    return 0;
}