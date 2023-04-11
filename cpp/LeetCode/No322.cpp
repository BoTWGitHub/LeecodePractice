/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
#include <unordered_set>
#include "Debug\MapDebug.h"
using namespace std;

class Solution { //top-down DP
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        unordered_map<int, int> mem;
        for(int coin : coins){
            mem[coin] = 1;
        }
        return dp(coins, amount, mem);
    }
private:
    int dp(vector<int>& coins, int amount, unordered_map<int, int> &mem){
        if(amount<0) return -1;
        if(mem.count(amount)>0) return mem[amount];
        int res = INT_MAX;
        for(int coin : coins){
            int temp = dp(coins, amount-coin, mem)+1;
            if(temp>0){
                res = min(res, temp);
            }
        }
        if(res==INT_MAX) res = -1;
        mem[amount] = res;
        return res;
    }
};

class Solution2 { //BFS
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        queue<int> q;
        q.push(amount);
        int res = 0;
        unordered_set<int> seen;
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0;i<size;i++){
                int a = q.front();
                q.pop();
                for(int coin : coins){
                    int temp = a-coin;
                    if(temp==0) return res;
                    else if(temp>0 && seen.count(temp)==0){
                        q.push(temp);
                        seen.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution2 solution;

    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl;

    coins = {2};
    amount = 3;
    cout << solution.coinChange(coins, amount) << endl;

    coins = {1};
    amount = 0;
    cout << solution.coinChange(coins, amount) << endl;

    coins = {1,2,5};
    amount = 100;
    cout << solution.coinChange(coins, amount) << endl;

    return 0;
}