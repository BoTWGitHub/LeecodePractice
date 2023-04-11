/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<pair<int, int>>> mem(arr.size(), vector<pair<int, int>>(arr.size(), {-1,-1}));
        return dp(arr, 0, arr.size()-1, mem).first;
    }
private:
    pair<int, int> dp(vector<int>& arr, int left, int right, vector<vector<pair<int, int>>>& mem){
        if(left==right-1) return {arr[left]*arr[right], max(arr[left], arr[right])};
        if(left==right) return {0, arr[left]};
        if(mem[left][right].first!=-1) return mem[left][right];

        int res = INT_MAX, high = 0;
        for(int i=left;i<right;i++){
            pair<int, int> ll = dp(arr, left, i, mem);
            pair<int, int> rr = dp(arr, i+1, right, mem);
            res = min(res, ll.first+rr.first+ll.second*rr.second);
            high = max(ll.second, rr.second);
        }
        return mem[left][right] = {res, high};
    }
};

int main(void){
    Solution solution;
    vector<int> arr;

    arr = {6,2,4};
    cout << solution.mctFromLeafValues(arr) << endl;

    arr = {4,11};
    cout << solution.mctFromLeafValues(arr) << endl;

    arr = {11,12,12};
    cout << solution.mctFromLeafValues(arr) << endl;

    arr = {6,15,5,2};
    cout << solution.mctFromLeafValues(arr) << endl;
    return 0;
}