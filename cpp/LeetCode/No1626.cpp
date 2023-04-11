/*
You are the manager of a basketball team. 
For the upcoming tournament, you want to choose the team with the highest overall score. 
The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. 
A conflict exists if a younger player has a strictly higher score than an older player. 
A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively
, return the highest overall score of all possible basketball teams.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;
        for(int i=0;i<n;i++) players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return dp(players, 0, -1, mem);
    }

private:
    int dp(vector<pair<int, int>>& players, int index, int last, vector<vector<int>>& mem){
        if(index==players.size()) return 0;
        if(last!=-1 && mem[index][last]!=-1) return mem[index][last];

        int res = dp(players, index+1, last, mem);
        if(last==-1 || players[index].second>=players[last].second){
            int pick = dp(players, index+1, index, mem) + players[index].second;
            res = max(pick, res);
        }
        if(last!=-1) mem[index][last] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> scores;
    vector<int> ages;

    scores = {1,3,5,10,15};
    ages = {1,2,3,4,5};
    cout << solution.bestTeamScore(scores, ages) << endl;

    scores = {4,5,6,5};
    ages = {2,1,2,1};
    cout << solution.bestTeamScore(scores, ages) << endl;

    scores = {1,2,3,5};
    ages = {8,9,10,1};
    cout << solution.bestTeamScore(scores, ages) << endl;

    scores = {6,5,1,7,6,5,5,4,10,4};
    ages = {3,2,5,3,2,1,4,4,5,1};
    cout << solution.bestTeamScore(scores, ages) << endl;
    return 0;
}