/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        return dp(s, 0, s.size()-1, mem);
    }
private:
    int dp(string& s, int left, int right, vector<vector<int>>& mem){
        if(left>=right) return 0;
        if(mem[left][right]!=-1) return mem[left][right];

        int res = 0;
        if(s[left]!=s[right]){
            res = min(dp(s, left+1, right, mem), dp(s, left, right-1, mem))+1;
        }
        else{
            res = dp(s, left+1, right-1, mem);
        }
        return mem[left][right] = res;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "zzazz";
    cout << solution.minInsertions(s) << endl;

    s = "mbadm";
    cout << solution.minInsertions(s) << endl;

    s = "leetcode";
    cout << solution.minInsertions(s) << endl;
    return 0;
}