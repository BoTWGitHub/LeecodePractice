/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int res = 0;
        for(int i=2;i<=n;i++){
            int temp = 1;
            int count = n%i;
            int div = n/i;
            for(int j=0;j<i;j++){
                if(count>0){
                    temp*=(div+1);
                    count--;
                }
                else temp*=div;
            }
            if(temp<=res) return res;
            res = temp;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;

    n = 2;
    cout << solution.integerBreak(n) << endl;

    n = 10;
    cout << solution.integerBreak(n) << endl;

    n = 58;
    cout << solution.integerBreak(n) << endl;
    return 0;
}