/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> mem(prices.size(), vector<int>(2, INT_MAX));
        return dp(prices, fee, 0, false, mem);
    }
private:
    int dp(vector<int>& prices, int fee, int index, bool holding, vector<vector<int>> &mem){
        if(index==prices.size()) return 0;
        if(mem[index][holding]!=INT_MAX) return mem[index][holding];

        int action, notAction;
        if(!holding){
            action = dp(prices, fee, index+1, true, mem) - prices[index];
            notAction = dp(prices, fee, index+1, false, mem);
        }
        else{
            action = dp(prices, fee, index+1, false, mem) + prices[index] - fee;
            notAction = dp(prices, fee, index+1, true, mem);
        }
        int res = max(action, notAction);
        return mem[index][holding] = res;
    }
};

int main(void){
    Solution solution;

    vector<int> prices;
    int fee;

    prices = {1,3,2,8,4,9};
    fee = 2;
    cout << solution.maxProfit(prices, fee) << endl;

    prices = {1,3,7,5,10,3};
    fee = 3;
    cout << solution.maxProfit(prices, fee) << endl;

    return 0;
}