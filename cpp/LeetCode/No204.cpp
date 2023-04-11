/*
Given an integer n, return the number of prime numbers that are strictly less than n.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> temp1;
        vector<int> temp2;
        for(int i=2;i<n;i++) temp1.push_back(i);
        int index = 0;
        while(temp1[index]*temp1[index]<n){
            for(int num : temp1){
                if(num==temp1[index] || num%temp1[index]>0) temp2.push_back(num);
            }
            temp1 = temp2;
            temp2.clear();
            index++;
        }
        return temp1.size();
    }
};

int main(void){
    Solution solution;
    int n;

    n = 10;
    cout << solution.countPrimes(n) << endl;

    n = 499979;
    cout << solution.countPrimes(n) << endl;

    n = 1500000;
    cout << solution.countPrimes(n) << endl;

    n = 5000000;
    cout << solution.countPrimes(n) << endl;
    return 0;
}