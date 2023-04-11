/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> mem(n+1, -1);
        return dp(n, mem);
    }
private:
    int dp(int n, vector<int> &mem){
        if(n==0) return 0;
        if(mem[n]!=-1) return mem[n];

        int res = INT_MAX;
        for(int i=1;i<=n;i++){
            int j = i*i;
            if(j<=n){
                res = min(res, dp(n-j, mem)+1);
            }
            else{
                break;
            }
        }
        return mem[n] = res;
    }
};

int main(void){
    Solution solution;
    int n;

    n = 12;
    cout << solution.numSquares(n) << endl;

    n = 13;
    cout << solution.numSquares(n) << endl;
    return 0;
}