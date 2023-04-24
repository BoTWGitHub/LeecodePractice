#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <map>
#include <string>
#include <algorithm>
#include <tuple>
#include <functional>
#include <array>
#include <list>
#include <thread>
#include <numeric>
#include "LeetCode\Debug\VectorDebug.h"

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

int main()
{
    return 0;
}
