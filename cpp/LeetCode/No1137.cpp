/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return 1;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};

int main(){
    Solution solution;

    int n = 25;
    cout << solution.tribonacci(n) << endl;
    return 0;
}
