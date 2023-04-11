/*
Given an array of intervals intervals where intervals[i] = [starti, endi]
, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            if(v1[0]!=v2[0]) return v1[0]<v2[0];
            return v1[1]<v2[1];
        });
        shift = intervals[0][0];
        int top = INT_MIN;
        for(vector<int>& interval : intervals) top = max(top, interval[1]);
        vector<vector<int>> mem(top-shift+1, vector<int>(intervals.size(), -1));
        return dp(intervals, INT_MIN, 0, mem);
    }
private:
    int shift;
    int dp(vector<vector<int>>& intervals, int upper, int index, vector<vector<int>>& mem){
        if(index==intervals.size()) return 0;
        if(upper!=INT_MIN && mem[upper-shift][index]!=-1) return mem[upper-shift][index];

        int res;
        if(intervals[index][0]>=upper){
            int take = dp(intervals, intervals[index][1], index+1, mem);
            int not_take = 1+dp(intervals, upper, index+1, mem);
            res = min(take, not_take);
        }
        else{
            res = 1+dp(intervals, upper, index+1, mem);
        }
        if(upper!=INT_MIN){
            mem[upper-shift][index] = res;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> intervals;

    intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    intervals = {{1,2},{1,2},{1,2}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    intervals = {{1,2},{2,3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;

    intervals = {{1,100},{11,22},{1,11},{2,12}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    return 0;
}