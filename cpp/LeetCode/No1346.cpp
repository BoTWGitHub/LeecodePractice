/*
Given an array arr of integers
, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int temp[2001] = {0};
        for(int num : arr){
            temp[num+1000]++;
        }
        for(int i=0;i<2001;i++){
            if(temp[i]>0){
                int target = (i-1000)*2, index = target+1000;
                if(target==0 && temp[index]>1){
                    if(temp[index]>1){
                        return true;
                    }
                }
                else{
                    if(index<2001 && index>0 && temp[index]>0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(void){
    vector<int> nums({-778,-481,842,495,44,1000,-572,977,240,-116,673,997,-958,-539,-964,-187,-701,-928,472,965,-672,-88,443,36,388,-127,115,704,-549,1000,998,291,633,423,57,-77,-543,72,328,-938,-192,382,179});
    Solution solution;
    printf("%d\r\n", solution.checkIfExist(nums));

    return 0;
}