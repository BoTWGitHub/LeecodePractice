/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, c = 0;
        for(int i=0;i<32;i++){
            int temp = (a&1)^(b&1)^c;
            res |= (temp<<i);
            c = (a&b|a&c|b&c)&1;
            a>>=1;
            b>>=1;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int a, b;

    a=1;
    b=2;
    cout << solution.getSum(a, b) << endl;

    a=2;
    b=3;
    cout << solution.getSum(a, b) << endl;

    a=-1;
    b=3;
    cout << solution.getSum(a, b) << endl;

    return 0;
}