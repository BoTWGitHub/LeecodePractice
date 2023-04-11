/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        print2DVector(dp);
        return dp[text1.size()][text2.size()];
    }
};

int main(void){
    Solution solution;

    string text1 = "tgattag";
    string text2 = "tgtgatcg";
    cout << solution.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}