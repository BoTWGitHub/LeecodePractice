/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.

If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.

Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.

Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<vector<vector<bool>>> mem(s1.size(), vector<vector<bool>>(s1.size(), vector<bool>(s1.size(), true)));
        return dp(s1, s2, 0, 0, s1.size()-1, mem);
    }
private:
    bool dp(string& s1, string& s2, int left, int l, int r, vector<vector<vector<bool>>>& mem){
        if(l==r) return s1[l]==s2[left];
        if(!mem[left][l][r]) return mem[left][l][r];

        bool res = true;
        for(int i=0;i<r-l+1;i++){
            if(s2[left+i]!=s1[l+i]){
                res = false;
                break;
            }
        }
        if(res) return res;
        for(int i=l;i<r;i++){
            if(dp(s1, s2, left, l, i, mem) && dp(s1, s2, left+i-l+1, i+1, r, mem)) return true;
            if(dp(s1, s2, left, i+1, r, mem) && dp(s1, s2, left+r-i, l, i, mem)) return true;
        }
        return mem[left][l][r] = false;
    }
};

int main(void){
    Solution solution;
    string s1;
    string s2;

    s1 = "great";
    s2 = "rgeat";
    cout << solution.isScramble(s1, s2) << endl;

    s1 = "abcde";
    s2 = "caebd";
    cout << solution.isScramble(s1, s2) << endl;

    s1 = "a";
    s2 = "a";
    cout << solution.isScramble(s1, s2) << endl;
    return 0;
}