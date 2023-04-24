/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
*/
#include <iostream>
#include "Debug\VectorDebug.h"

class SegmentTree{
public:
    SegmentTree(std::vector<int>& nums){
        n = nums.size();
        tree = std::vector<int>(4*n);
        build(nums, 0, n-1);
    }
    int sum(int left, int right, int l, int r, int index=1){
        if(l>r) return 0;
        if(l==left && r==right) return tree[index];
        int mid = (right-left)/2+left;
        return sum(left, mid, l, std::min(r, mid), index*2) + sum(mid+1, right, std::max(l, mid+1), r, index*2+1);
    }
    void updateValue(int left, int right, int i, int val, int index=1){
        if(left==right) tree[index] = val;
        else{
            int mid = (right-left)/2 + left;
            if(i<=mid) updateValue(left, mid, i, val, index*2);
            else updateValue(mid+1, right, i, val, index*2+1);
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
private:
    int n;
    std::vector<int> tree;
    void build(std::vector<int>& nums, int left, int right, int index=1){
        if(left==right){
            tree[index] = nums[left];
        }
        else{
            int mid = (right-left)/2+left;
            build(nums, left, mid, index*2);
            build(nums, mid+1, right, index*2+1);
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
};

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        n = nums.size();
        st = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        st->updateValue(0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st->sum(0, n-1, left, right);
    }
private:
    int n;
    SegmentTree *st;
};

int main(void){
    std::vector<int> nums = {1,3,5};
    NumArray solution(nums);
    std::cout << solution.sumRange(0,2) << std::endl;
    solution.update(1,2);
    std::cout << solution.sumRange(0,2) << std::endl;

    /*std::vector<int> nums = {-28,-39,53,65,11,-56,-65,-39,-43,97};
    NumArray solution(nums);
    std::cout << solution.sumRange(5,6) << std::endl;
    solution.update(9,27);
    std::cout << solution.sumRange(2,3) << std::endl;
    std::cout << solution.sumRange(6,7) << std::endl;
    solution.update(1,-82);
    solution.update(3,-72);
    std::cout << solution.sumRange(3,7) << std::endl;
    std::cout << solution.sumRange(1,8) << std::endl;
    solution.update(5,13);
    solution.update(4,-67);*/
    
    return 0;
}