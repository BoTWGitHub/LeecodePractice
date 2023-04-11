/*
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};
        vector<int> temp = grayCode(n-1);
        vector<int> res = temp;
        int i=1<<(n-1);
        for(int j=0;j<temp.size();j++){
            temp[j]|=i;
        }
        res.insert(res.end(), temp.rbegin(), temp.rend());
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<int> res;

    n=2;
    res = solution.grayCode(n);
    printVector(res);

    n=1;
    res = solution.grayCode(n);
    printVector(res);

    n=3;
    res = solution.grayCode(n);
    printVector(res);
    
    return 0;
}