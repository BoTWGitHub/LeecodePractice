/*
You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"

class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<std::vector<int>> sortIntervals;
        for(int i=0;i<n;i++){
            sortIntervals.push_back({intervals[i][0], intervals[i][1], i});
        }
        sort(sortIntervals.begin(), sortIntervals.end());
        std::vector<int> res(n, -1);
        for(int i=0;i<n;i++){
            int target = intervals[i][1];
            int left = 0, right = n-1;
            while(left<right){
                int mid = (right-left)/2+left;
                if(sortIntervals[mid][0]>=target) right = mid;
                else left = mid+1;
            }
            if(sortIntervals[left][0]>=target){
                res[i] = sortIntervals[left][2];
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<std::vector<int>> intervals;
    std::vector<int> res;

    intervals = {{1,2}};
    res = solution.findRightInterval(intervals);
    printVector(res);

    intervals = {{3,4},{2,3},{1,2}};
    res = solution.findRightInterval(intervals);
    printVector(res);

    intervals = {{1,4},{2,3},{3,4}};
    res = solution.findRightInterval(intervals);
    printVector(res);
    return 0;
}