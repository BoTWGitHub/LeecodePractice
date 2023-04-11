/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(n==0){
            res.push_back(newInterval);
            return res;
        }
        int left = findLower(intervals, newInterval[0]);
        for(int i=0;i<left;i++) res.push_back(intervals[i]);
        
        if(intervals[left][0]<=newInterval[0]){
            res.push_back(intervals[left]);
            if(newInterval[0]>res.back()[1]){
                res.push_back(newInterval);
            }
            else{
                res.back()[1] = max(res.back()[1], newInterval[1]);
            }
        }
        else{
            res.push_back(newInterval);
            if(intervals[left][0]>res.back()[1]){
                res.push_back(intervals[left]);
            }
            else{
                res.back()[1] = max(res.back()[1], intervals[left][1]);
            }
        }
        
        for(int i=left+1;i<n;i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
private:
    int findLower(vector<vector<int>>& intervals, int target){
        int left = 0, right = intervals.size()-1;
        while(left<right){
            int mid = (right-left+1)/2 + left;
            if(intervals[mid][0]<=target) left = mid;
            else right = mid-1;
        }
        return left;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> intervals;
    vector<int> newInterval;
    vector<vector<int>> res;

    intervals = {{1,3},{6,9}};
    newInterval = {2,5};
    res = solution.insert(intervals, newInterval);
    print2DVector(res);

    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    res = solution.insert(intervals, newInterval);
    print2DVector(res);
    return 0;
}