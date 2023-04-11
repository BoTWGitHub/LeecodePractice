/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return dp(s, 0, n-1, mem);
    }
private:
    int dp(string& s, int l, int r, vector<vector<int>>& mem){
        if(l==r) return 1;
        else if(l>r) return 0;
        if(mem[l][r]!=-1) return mem[l][r];
        
        int res;
        if(s[l]==s[r]){
            res = dp(s, l+1, r-1, mem)+2;
        }
        else{
            res = max(dp(s, l+1, r, mem), dp(s, l, r-1, mem));
        }
        
        return mem[l][r] = res;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "bbbab";
    cout << solution.longestPalindromeSubseq(s) << endl;

    s = "cbbd";
    cout << solution.longestPalindromeSubseq(s) << endl;
    return 0;
}