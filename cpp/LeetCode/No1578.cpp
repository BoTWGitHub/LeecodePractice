/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. 
She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. 
You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0, right = 0;
        int tempSum = 0, maxT = 0;
        int res = 0;
        while(left<colors.size() && right<colors.size()){
            if(colors[left]==colors[right]){
                tempSum+=neededTime[right];
                maxT = max(maxT, neededTime[right]);
                right++;
            }
            else{
                res+=(tempSum-maxT);
                tempSum = 0;
                maxT = 0;
                left = right;
            }
        }
        res+=(tempSum-maxT);
        return res;
    }
};

int main(){
    Solution solution;

    string colors = "abaac";
    vector<int> neededTime = {1,2,3,4,5};
    cout << solution.minCost(colors, neededTime) << endl;
    return 0;
}
