/*
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. 
The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. 
Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
#include <array>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        array<int, 101> populations = {0};
        int maxPopulation = 0;
        for(vector<int>& log : logs){
            for(int y=log[0];y<log[1];y++){
                populations[y-1950]++;
                maxPopulation = max(maxPopulation, populations[y-1950]);
            }
        }
        for(int i=0;i<populations.size();i++){
            if(populations[i]==maxPopulation) return i+1950;
        }
        return 0;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> logs;

    logs = {{1993,1999},{2000,2010}};
    cout << solution.maximumPopulation(logs) << endl;

    logs = {{1950,1961},{1960,1971},{1970,1981}};
    cout << solution.maximumPopulation(logs) << endl;

    logs = {{2008,2026},{2004,2008},{2034,2035},{1999,2050},{2049,2050},{2011,2035},{1966,2033},{2044,2049}};
    cout << solution.maximumPopulation(logs) << endl;
    return 0;
}