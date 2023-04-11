/*
You have n flower seeds. Every seed must be planted first before it can begin to grow, then bloom. 
Planting a seed takes time and so does the growth of a seed. 
You are given two 0-indexed integer arrays plantTime and growTime, of length n each:

plantTime[i] is the number of full days it takes you to plant the ith seed. 
Every day, you can work on planting exactly one seed. 
You do not have to work on planting the same seed on consecutive days
, but the planting of a seed is not complete until you have worked plantTime[i] days on planting it in total.
growTime[i] is the number of full days it takes the ith seed to grow after being completely planted. 
After the last day of its growth, the flower blooms and stays bloomed forever.
From the beginning of day 0, you can plant the seeds in any order.

Return the earliest possible day where all seeds are blooming.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int sumOfPlant = 0;
        for(int time : plantTime) sumOfPlant+=time;
        backtrack(plantTime, growTime, 0, sumOfPlant);
        return res;
    }
private:
    int res = INT_MAX;
    void backtrack(vector<int>& plantTime, vector<int>& growTime, int days, int sumOfPlant){
        getchar();
        cout << days << "," << sumOfPlant << endl;
        printVector(plantTime);
        printVector(growTime);
        if(sumOfPlant==0){
            int temp = 0;
            for(int time : growTime) temp = max(temp, time);
            cout << "res " << days+temp << endl;
            res = min(res, days+temp);
            return;
        }

        for(int i=0;i<plantTime.size();i++){
            if(plantTime[i]==0 && growTime[i]>0){
                growTime[i]--;
            }
        }

        for(int i=0;i<plantTime.size();i++){
            if(plantTime[i]>0){
                plantTime[i]--;
                sumOfPlant--;
                backtrack(plantTime, growTime, days+1, sumOfPlant);
                plantTime[i]++;
                sumOfPlant++;
            }
        }

        for(int i=0;i<plantTime.size();i++){
            if(plantTime[i]==0){
                growTime[i]++;
            }
        }
    }
};

int main(void){
    Solution solution;
    vector<int> plantTime;
    vector<int> growTime;

    plantTime = {1,4,3};
    growTime = {2,3,1};
    cout << solution.earliestFullBloom(plantTime, growTime) << endl;

    /*plantTime = {1,2,3,2};
    growTime = {2,1,2,1};
    cout << solution.earliestFullBloom(plantTime, growTime) << endl;*/

    /*plantTime = {1};
    growTime = {1};
    cout << solution.earliestFullBloom(plantTime, growTime) << endl;

    plantTime = {3,11,29,4,4,26,26,12,13,10,30,19,27,2,10};
    growTime = {10,13,22,17,18,15,21,11,24,14,18,23,1,30,6};
    cout << solution.earliestFullBloom(plantTime, growTime) << endl;*/

    return 0;
}