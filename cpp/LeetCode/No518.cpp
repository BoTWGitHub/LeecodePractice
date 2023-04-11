/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> mem(coins.size()+1,vector<int>(amount+1,-1));
        return dp(0,amount,coins,mem);
    }
private:
    int dp(int index, int amount, vector<int>& coins, vector<vector<int>>& mem){
        if(amount<0) return 0;
        if(amount==0) return 1;
        if(index==coins.size()) return 0;
        if(mem[index][amount]!=-1) return mem[index][amount];
		
		int res = dp(index,amount-coins[index],coins,mem) + dp(index+1,amount,coins,mem);
		return mem[index][amount] = res;
    }
};

int main(void){
    Solution solution;

    int amount;
    vector<int> coins;

    amount = 5;
    coins = {1,2,5};
    cout << solution.change(amount, coins) << endl;

    amount = 3;
    coins = {2};
    cout << solution.change(amount, coins) << endl;

    amount = 10;
    coins = {10};
    cout << solution.change(amount, coins) << endl;

    return 0;
}