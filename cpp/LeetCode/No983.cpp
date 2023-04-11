/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> mem(days.size(), vector<int>(30, -1));
        return dp(days, costs, 0, 0, mem);
    }
private:
    vector<int> daysLeft = {0,6,29};
    int dp(vector<int>& days, vector<int>& costs, int index, int freeLeft, vector<vector<int>> &mem){
        if(index==days.size()) return 0;
        if(mem[index][freeLeft]!=-1) return mem[index][freeLeft];

        int res = INT_MAX;
        if(freeLeft==0 || days[index]-days[index-1]>freeLeft){
            for(int i=0;i<3;i++){
                res = min(res, dp(days, costs, index+1, daysLeft[i], mem)+costs[i]);
            }
        }
        else{
            res = min(res, dp(days, costs, index+1, freeLeft - days[index]+days[index-1], mem));
        }
        return mem[index][freeLeft] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> days;
    vector<int> costs;

    days = {1,4,5,7,8,20};
    costs = {2,7,15};
    cout << solution.mincostTickets(days, costs) << endl;

    days = {1,2,3,4,5,6,7,8,9,10,30,31};
    costs = {2,7,15};
    cout << solution.mincostTickets(days, costs) << endl;

    return 0;
}