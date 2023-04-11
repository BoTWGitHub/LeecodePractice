/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> player;
        for(vector<int>& match : matches){
            player[match[0]].first++;
            player[match[1]].second++;
        }
        vector<vector<int>> res(2);
        for(auto p : player){
            if(p.second.second==0) res[0].push_back(p.first);
            if(p.second.second==1) res[1].push_back(p.first);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> matches;
    vector<vector<int>> res;

    matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    res = solution.findWinners(matches);
    print2DVector(res);

    matches = {{2,3},{1,3},{5,4},{6,4}};
    res = solution.findWinners(matches);
    print2DVector(res);
    return 0;
}