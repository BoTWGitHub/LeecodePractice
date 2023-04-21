/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. 
If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        int swapIndex = -1;
        for(int i=0;i<digits.size()-1;i++){
            if(digits[i+1]<digits[i]){
                swapIndex = i+1;
                break;
            }
        }
        if(swapIndex==-1) return -1;
        for(int i=0;i<swapIndex;i++){
            if(digits[i]>digits[swapIndex]){
                swap(digits[i], digits[swapIndex]);
                break;
            }
        }
        int left = 0, right = swapIndex-1;
        while(left<right){
            swap(digits[left++], digits[right--]);
        }
        long long res = 0;
        for(int i=digits.size()-1;i>=0;i--){
            res = res*10+digits[i];
        }
        return res>INT_MAX?-1:res;
    }
};

int main(void){
    Solution solution;
    int n;

    n = 12;
    cout << solution.nextGreaterElement(n) << endl;

    n = 21;
    cout << solution.nextGreaterElement(n) << endl;

    n = 2143;
    cout << solution.nextGreaterElement(n) << endl;
    return 0;
}