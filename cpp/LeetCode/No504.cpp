/*
Given an integer num, return a string of its base 7 representation.
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        bool neg = num<0;
        num = abs(num);
        int res = 0, mul = 1;
        while(num>0){
            res = res + num%7*mul;
            num/=7;
            mul*=10;
        }
        if(neg) res = -res;
        return to_string(res);
    }
};

int main(void){
    Solution solution;
    int num;

    num = 30;
    cout << solution.convertToBase7(num) << endl;

    num = 100;
    cout << solution.convertToBase7(num) << endl;

    num = -7;
    cout << solution.convertToBase7(num) << endl;

    return 0;
}