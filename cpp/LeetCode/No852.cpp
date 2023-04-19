/*
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size()-2;
        while(left<=right){
            int mid = (right-left)/2+left;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};

int main(void){
    Solution solution;
    vector<int> arr;

    arr = {0,1,0};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0,2,1,0};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0,10,5,2};
    cout << solution.peakIndexInMountainArray(arr) << endl;

    arr = {0,1,2,3,10,5,2};
    cout << solution.peakIndexInMountainArray(arr) << endl;
    return 0;
}