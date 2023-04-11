/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> mem(prices.size(), vector<int>(2, -1));
        return dp(prices, 0, false, mem);
    }
private:
    int dp(vector<int> &prices, int index, bool holding, vector<vector<int>> &mem){
        if(index>=prices.size()) return 0;
        if(mem[index][holding]!=-1) return mem[index][holding];

        int res = 0;
        if(!holding){
            int buy = dp(prices, index+1, true, mem) - prices[index];
            int notbuy = dp(prices, index+1, false, mem);
            res = max(buy, notbuy);
        }
        else{
            int sell = dp(prices, index+2, false, mem) + prices[index];
            int notsell = dp(prices, index+1, true, mem);
            res = max(sell, notsell);
        }
        mem[index][holding] = res;
        return res;
    }
};

int main(){
    Solution solution;

    vector<int> prices;

    prices = {1,2,3,0,2};
    cout << solution.maxProfit(prices) << endl;

    prices = {1};
    cout << solution.maxProfit(prices) << endl;

    return 0;
}
