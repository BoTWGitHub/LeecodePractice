/*
Imagine you have a special keyboard with the following keys:

A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxA(int n) {
        vector<map<pair<int, int>, int>> mem(n+1);
        return dp(n, 0, 0, mem);
    }
private:
    int dp(int n, int copy, int current, vector<map<pair<int, int>, int>>& mem){
        if(n<=0) return 0;
        if(mem[n].count({copy, current})) return mem[n][{copy, current}];

        int res = 0;
        if(copy<2){
            int typeA = dp(n-1, copy, current+1, mem)+1;
            res = max(res, typeA);
        }
        int selectAndCopy = dp(n-2, current, current, mem);
        int paste = dp(n-1, copy, current+copy, mem) + copy;
        res = max(res, max(selectAndCopy, paste));
        return mem[n][{copy, current}] = res;
    }
};

int main(void){
    Solution solution;
    int n;

    n = 3;
    cout << solution.maxA(n) << endl;

    n = 7;
    cout << solution.maxA(n) << endl;

    n = 50;
    cout << solution.maxA(n) << endl;
    return 0;
}