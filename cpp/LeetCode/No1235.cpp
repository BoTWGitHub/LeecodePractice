/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays
, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int, int>, int>> jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> mem(startTime.size(), -1);
        return dp(jobs, 0, mem);
    }
private:
    int dp(vector<pair<pair<int, int>, int>>& jobs, int index, vector<int>& mem){
        if(index==jobs.size()) return 0;
        if(mem[index]!=-1) return mem[index];

        int nextJob = findNextIndex(jobs, index+1, jobs[index].first.second);
        int takeJob = jobs[index].second+dp(jobs, nextJob, mem);
        int notTakeJob = dp(jobs, index+1, mem);
        int res = max(takeJob, notTakeJob);
        return mem[index]=res;
    }

    int findNextIndex(vector<pair<pair<int, int>, int>>& jobs, int left, int end){
        int right = jobs.size()-1;
        while(left<right){
            int mid=(right-left)/2+left;
            if(jobs[mid].first.first>=end) right = mid;
            else left=mid+1;
        }
        if(left==jobs.size()-1 && jobs[left].first.first<end) return left+1;
        return left;
    }
};

int main(void){
    Solution solution;
    vector<int> startTime;
    vector<int> endTime;
    vector<int> profit;

    startTime = {1,2,3,3};
    endTime = {3,4,5,6};
    profit = {50,10,40,70};
    cout << solution.jobScheduling(startTime, endTime, profit) << endl;

    startTime = {1,2,3,4,6};
    endTime = {3,5,10,6,9};
    profit = {20,20,100,70,60};
    cout << solution.jobScheduling(startTime, endTime, profit) << endl;

    startTime = {1,1,1};
    endTime = {2,3,4};
    profit = {5,6,4};
    cout << solution.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}