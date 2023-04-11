/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long result = 0;
        int map[60] = {0};
        for(int t : time){
            map[t%60]++;
        }
        for(int i=0;i<=30;i++){
            if(i==0 || i==30){
                if(map[i]>0){
                    result+=((long)map[i]*(long)(map[i]-1))/2;
                }
            }
            else{
                result+=(map[i]*map[60-i]);
            }
        }
        return result;
    }
};

int main(void){
    Solution solution;
    vector<int> time{30,20,150,100,40};
    cout << solution.numPairsDivisibleBy60(time) << endl;
    return 0;
}