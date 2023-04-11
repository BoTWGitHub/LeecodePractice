/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. 
You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. 
Since the answer may be very large, return it modulo 10^9 + 7.

In a tiling, every square must be covered by a tile. 
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board 
such that exactly one of the tilings has both squares occupied by a tile.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
        return dp(n, n, mem);
    }
private:
    int mod=1e9+7;
    int dp(int n1, int n2, vector<vector<int>> &mem){
        if(n1==0 && n2==0) return 1;
        if(n1<0 || n2<0) return 0;
        if(mem[n1][n2]!=-1) return mem[n1][n2];

        int res = 0;
        if(n1==n2){
            res = (res+dp(n1-1, n2-1, mem))%mod;
            res = (res+dp(n1-2, n2-2, mem))%mod;
            res = (res+dp(n1-1, n2-2, mem))%mod;
            res = (res+dp(n1-2, n2-1, mem))%mod;
        }
        else if(n1>n2){
            res = (res+dp(n1-2, n2, mem))%mod;
            res = (res+dp(n1-2, n2-1, mem))%mod;
        }
        else{
            res = (res+dp(n1, n2-2, mem))%mod;
            res = (res+dp(n1-1, n2-2, mem))%mod;
        }
        
        return mem[n1][n2] = res;
    }
};

int main(void){
    Solution solution;
    int n;

    n=3;
    cout << solution.numTilings(n) << endl;

    n=1;
    cout << solution.numTilings(n) << endl;

    n=4;
    cout << solution.numTilings(n) << endl;

    return 0;
}