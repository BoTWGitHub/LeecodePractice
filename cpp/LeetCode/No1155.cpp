/*
You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target
, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> mem(n, vector<int>(target+1, -1));
        return dp(n, k, target, 0, mem);
    }
private:
    const int mod = 1e9+7;
    int dp(int n, int k, int target, int index, vector<vector<int>> &mem){
        if(target<0) return 0;
        if(index==n) return target==0?1:0;
        if(mem[index][target]!=-1) return mem[index][target];

        int res = 0;
        for(int i=1;i<=k;i++){
            res = (res + dp(n, k, target-i, index+1, mem))%mod;
        }
        return mem[index][target] = res;
    }
};

int main(void){
    Solution solution;
    int n, k, target;

    n=1;
    k=6;
    target=3;
    cout << solution.numRollsToTarget(n, k, target) << endl;

    n=2;
    k=6;
    target=7;
    cout << solution.numRollsToTarget(n, k, target) << endl;

    n=30;
    k=30;
    target=500;
    cout << solution.numRollsToTarget(n, k, target) << endl;

    return 0;
}