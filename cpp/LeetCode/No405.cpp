/*
Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned int x = num;
        string res = "";
        while(x>0){
            int mod = x%16;
            char c;
            if(mod>9) c='a'+mod-10;
            else c='0'+mod;
            res.insert(res.begin(), c);;
            x/=16;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int num;

    num = 26;
    cout << solution.toHex(num) << endl;

    num = -1;
    cout << solution.toHex(num) << endl;

    return 0;
}