/*
Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1]
, so arr = [1,2,3,4] after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. 
Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int index = arr.size()-1;
        vector<int> res;
        while(index>0){
            int k = -1;
            for(int i=0;i<=index;i++){
                if(arr[i]==temp[index]){
                    k = i;
                    break;
                }
            }
            if(k!=index){
                if(k>0){
                    flip(arr, k+1);
                    res.push_back(k+1);
                }
                flip(arr, index+1);
                res.push_back(index+1);
            }
            index--;
        }
        return res;
    }
private:
    void flip(vector<int>& arr, int k){
        int left = 0, right = k-1;
        while(left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main(void){
    Solution solution;
    vector<int> arr;
    vector<int> res;

    arr = {3,2,4,1};
    res = solution.pancakeSort(arr);
    printVector(res);

    arr = {1,2,3};
    res = solution.pancakeSort(arr);
    printVector(res);
    return 0;
}