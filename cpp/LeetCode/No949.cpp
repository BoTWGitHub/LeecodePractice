/*
Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. 
The earliest 24-hour time is 00:00, and the latest is 23:59.

Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include "Debug\VectorDebug.h"

//step 1: make permutation
//step 2: check if it make a valid clock
//step 3: compare with result to check the latest one
//step 4: convert to clock string

class Solution {
public:
    std::string largestTimeFromDigits(std::vector<int>& arr) {
        std::vector<int> res(4, -1);
        backtrack(arr, 0, res);
        if(res[0] == -1) return "";
        return makeClockString(res);
    }
private:
    void backtrack(std::vector<int>& arr, int step, std::vector<int>& res){
        if(step==arr.size()){
            if(checkClockIsValid(arr)){
                cmpClock(arr, res);
            }
            return;
        }

        for(int i=step;i<arr.size();i++){
            std::swap(arr[step], arr[i]);
            backtrack(arr, step+1, res);
            std::swap(arr[step], arr[i]);
        }
    }
    bool checkClockIsValid(std::vector<int>& arr){
        int hour = arr[0]*10+arr[1];
        if(hour>23) return false;
        int minute = arr[2]*10+arr[3];
        if(minute>59) return false;
        return true;
    }
    void copyVector(std::vector<int>& src, std::vector<int>& dst){
        for(int i=0;i<4;i++){
            dst[i] = src[i];
        }
    }
    void cmpClock(std::vector<int>& src, std::vector<int>& dst){
        if(dst[0]==-1){
            copyVector(src, dst);
            return;
        }
        
        int h1 = src[0]*10+src[1];
        int h2 = dst[0]*10+dst[1];
        if(h1>h2){
            copyVector(src, dst);
        }
        else if(h1==h2){
            int m1 = src[2]*10+src[3];
            int m2 = dst[2]*10+dst[3];
            if(m1>m2){
                copyVector(src, dst);
            }
        }
    }
    std::string makeClockString(std::vector<int>& arr){
        int hour = arr[0]*10+arr[1];
        int minute = arr[2]*10+arr[3];
        std::string res = "";
        if(hour<10){
            res.push_back('0');
        }
        res+=std::to_string(hour);
        res.push_back(':');
        if(minute<10){
            res.push_back('0');
        }
        res+=std::to_string(minute);
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<int> arr;

    arr = {1,2,3,4};
    std::cout << solution.largestTimeFromDigits(arr) << std::endl;

    arr = {5,5,5,5};
    std::cout << solution.largestTimeFromDigits(arr) << std::endl;

    arr = {0,0,0,0};
    std::cout << solution.largestTimeFromDigits(arr) << std::endl;
    return 0;
}