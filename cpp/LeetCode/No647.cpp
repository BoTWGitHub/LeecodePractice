/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), 0));
        int res = s.size();
        dp(s, 0, s.size()-1, mem, res);
        return res;
    }
private:
    int dp(string& s, int left, int right, vector<vector<int>>& mem, int& res){
        if(mem[left][right]>0) return mem[left][right];
        if(left==right-1){
            if(s[left]==s[right]){
                mem[left][right] = 2;
                res++;
            }
            else mem[left][right] = 1;
            return mem[left][right];
        }
        if(left==right) return mem[left][right] = 2;
        
        int ret = 1;
        if(s[left]==s[right] && dp(s, left+1, right-1, mem, res)==2){
            ret = 2;
            res++;
        }
        mem[left][right] = ret;
        dp(s, left+1, right, mem, res);
        dp(s, left, right-1, mem, res);
        return ret;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "abc";
    cout << solution.countSubstrings(s) << endl;

    s = "aaa";
    cout << solution.countSubstrings(s) << endl;

    s = "abcba";
    cout << solution.countSubstrings(s) << endl;

    s = "xkjkqlajprjwefilxgpdpebieswu";
    cout << solution.countSubstrings(s) << endl;
    return 0;
}