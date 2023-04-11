/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: 
the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<vector<int>> mem(2, vector<int>(values.size(), -1));
        return dp(values, false, 0, mem);
    }
private:
    int dp(vector<int>& values, bool picked, int index, vector<vector<int>>& mem){
        if(index==values.size()) return -index;
        if(mem[picked][index]!=-1) return mem[picked][index];

        int res = 0;
        if(picked){
            res = max(values[index]-index, dp(values, true, index+1, mem));
        }
        else{
            res = max(values[index]+index+dp(values, true, index+1, mem), dp(values, false, index+1, mem));
        }
        return mem[picked][index] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> values;

    values = {8,1,5,2,6};
    cout << solution.maxScoreSightseeingPair(values) << endl;

    values = {1,2};
    cout << solution.maxScoreSightseeingPair(values) << endl;
    return 0;
}