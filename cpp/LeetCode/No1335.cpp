/*
You want to schedule a list of jobs in d days. Jobs are dependent 
(i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. 
The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. 
The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. 
If you cannot find a schedule for the jobs return -1.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        vector<vector<int>> mem(jobDifficulty.size(), vector<int>(d, -1));
        return dp(jobDifficulty, d, 0, 1, mem);
    }
private:
    int dp(vector<int>& jobDifficulty, int d, int index, int day, vector<vector<int>> &mem){
        if(mem[index][day-1]!=-1) return mem[index][day-1];

        if(day==d){
            int hardest = 0;
            for(int i=index;i<jobDifficulty.size();i++){
                hardest = max(hardest, jobDifficulty[i]);
            }
            mem[index][day-1] = hardest;
            return mem[index][day-1];
        }
        
        int max_pick = jobDifficulty.size() - index - (d-day);
        int res = INT_MAX;
        int hardest = 0;
        for(int i=0;i<max_pick;i++){
            hardest = max(hardest, jobDifficulty[index+i]);
            int temp = hardest + dp(jobDifficulty, d, index+i+1, day+1, mem);
            res = min(res, temp);
        }
        mem[index][day-1] = res;
        return res;
    }
};

int main(){
    Solution solution;

    vector<int> jobDifficulty = {6,5,4,3,2,1};
    int d = 2;
    cout << solution.minDifficulty(jobDifficulty, d) << endl; //ans = 7

    jobDifficulty = {9,9,9};
    d = 4;
    cout << solution.minDifficulty(jobDifficulty, d) << endl; //ans = -1

    jobDifficulty = {1,1,1};
    d = 3;
    cout << solution.minDifficulty(jobDifficulty, d) << endl; //ans = 3

    jobDifficulty = {7,1,7,1,7,1};
    d = 3;
    cout << solution.minDifficulty(jobDifficulty, d) << endl; //ans = 15
    return 0;
}
