/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x<0){
            if(x==INT_MIN) return 0;
            return -reverse(-x);
        }
        int res = 0;
        while(x){
            if(res>INT_MAX/10) return 0;
            res*=10;
            if(res>INT_MAX-x%10) return 0;
            res+=x%10;
            x/=10;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int x;

    x = 123;
    cout << solution.reverse(x) << endl;

    x = -123;
    cout << solution.reverse(x) << endl;

    x = 120;
    cout << solution.reverse(x) << endl;
    return 0;
}