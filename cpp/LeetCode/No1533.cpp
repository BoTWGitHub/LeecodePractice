/*
We have an integer array arr, where all the integers in arr are equal except for one integer which is larger than the rest of the integers. 
You will not be given direct access to the array, instead, you will have an API ArrayReader which have the following functions:

int compareSub(int l, int r, int x, int y): where 0 <= l, r, x, y < ArrayReader.length(), l <= r and x <= y. 
The function compares the sum of sub-array arr[l..r] with the sum of the sub-array arr[x..y] and returns:
  1 if arr[l]+arr[l+1]+...+arr[r]  >  arr[x]+arr[x+1]+...+arr[y].
  0 if arr[l]+arr[l+1]+...+arr[r]  == arr[x]+arr[x+1]+...+arr[y].
 -1 if arr[l]+arr[l+1]+...+arr[r]  <  arr[x]+arr[x+1]+...+arr[y].
int length(): Returns the size of the array.
You are allowed to call compareSub() 20 times at most. 
You can assume both functions work in O(1) time.

Return the index of the array arr which has the largest integer.
*/
#include <iostream>
#include <vector>
using namespace std;

// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
  public:
    ArrayReader(vector<int> nums){
        n = nums.size();
        prefix = vector<int>(n, nums[0]);
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1]+nums[i];
    }
    // Compares the sum of arr[l..r] with the sum of arr[x..y] 
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y){
        if(l<0 || r>=n || r<l || x<0 || y>=n || y<x) return 2;
        int res1, res2;
        if(l>0) res1 = prefix[r]-prefix[l-1];
        else res1 = prefix[r];
        if(x>0) res2 = prefix[y]-prefix[x-1];
        else res2 = prefix[y];
        
        if(res1==res2) return 0;
        else if(res1>res2) return 1;
        else return -1;
    }
    // Returns the length of the array
    int length(){
        return n;
    }
private:
    vector<int> prefix;
    int n;
};

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int left = 0, right = n-1;
        while(left<right){
            int m1 = (right-left)/2 + left;
            int m2 = m1+(right-left)%2;
            if(reader.compareSub(left, m1, m2, right)==1) right = m1;
            else left = m2;
        }
        return left;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    ArrayReader reader(nums);

    nums = {7,7,7,7,10,7,7,7};
    reader = ArrayReader(nums);
    cout << solution.getIndex(reader) << endl;

    nums = {6,6,12};
    reader = ArrayReader(nums);
    cout << solution.getIndex(reader) << endl;
    return 0;
}