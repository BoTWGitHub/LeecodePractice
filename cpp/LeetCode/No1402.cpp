/*
A chef has collected data on the satisfaction level of his n dishes. 
Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level 
i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0, last = 0;
        for(int i=satisfaction.size()-1;i>=0;i--){
            int temp = res + satisfaction[i] + last;
            last+=satisfaction[i];
            if(temp<=res) return res;
            else res = temp;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> satisfaction;

    satisfaction = {-1,-8,0,5,-9};
    cout << solution.maxSatisfaction(satisfaction) << endl;

    satisfaction = {4,3,2};
    cout << solution.maxSatisfaction(satisfaction) << endl;

    satisfaction = {-1,-4,-5};
    cout << solution.maxSatisfaction(satisfaction) << endl;
    return 0;
}