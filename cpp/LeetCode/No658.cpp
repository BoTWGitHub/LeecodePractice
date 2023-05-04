/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
*/
#include <iostream>
#include "Debug\VectorDebug.h"

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n-k;
        while(left<right){
            int mid = (right-left)/2+left;
            if(x-arr[mid]>arr[mid+k]-x) left = mid+1;
            else right = mid;
        }

        std::vector<int> res;
        for(int i=left;i<left+k;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> arr;
    int k;
    int x;
    std::vector<int> res;

    arr = {1,2,3,4,5};
    k = 4;
    x = 3;
    res = solution.findClosestElements(arr, k, x);
    printVector(res);

    arr = {1,2,3,4,5};
    k = 4;
    x = -1;
    res = solution.findClosestElements(arr, k, x);
    printVector(res);

    arr = {1,1,1,10,10,10};
    k = 1;
    x = 9;
    res = solution.findClosestElements(arr, k, x);
    printVector(res);
    return 0;
}