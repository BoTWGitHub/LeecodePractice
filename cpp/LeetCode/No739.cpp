/*
Given an array of integers temperatures represents the daily temperatures
, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> sk;
        for(int i=0;i<n;i++){
            while(!sk.empty() && temperatures[i]>temperatures[sk.top()]){
                int temp = sk.top();
                sk.pop();
                res[temp] = i-temp;
            }
            sk.push(i);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> temperatures;
    vector<int> res;

    temperatures = {73,74,75,71,69,72,76,73};
    res = solution.dailyTemperatures(temperatures);
    printVector(res);

    temperatures = {30,40,50,60};
    res = solution.dailyTemperatures(temperatures);
    printVector(res);

    temperatures = {30,60,90};
    res = solution.dailyTemperatures(temperatures);
    printVector(res);
    return 0;
}