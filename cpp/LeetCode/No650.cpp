/*
There is only one character 'A' on the screen of a notepad. 
You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int divider = 2;
        while(n>1){
            while(n%divider==0){
                res+=divider;
                n/=divider;
            }
            divider++;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;

    n = 3;
    cout << solution.minSteps(n) << endl;

    n = 1;
    cout << solution.minSteps(n) << endl;
    return 0;
}