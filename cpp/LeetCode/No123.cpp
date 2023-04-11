/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. 
You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, 
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }

    return t2Profit;
  }
};

int main(){
    Solution solution;

    vector<int> prices;

    prices = {3,3,5,0,0,3,1,4};
    cout << solution.maxProfit(prices) << endl;

    prices = {1,2,3,4,5};
    cout << solution.maxProfit(prices) << endl;

    prices = {7,6,4,3,1};
    cout << solution.maxProfit(prices) << endl;

    prices = {6,1,3,2,4,7};
    cout << solution.maxProfit(prices) << endl;

    return 0;
}
