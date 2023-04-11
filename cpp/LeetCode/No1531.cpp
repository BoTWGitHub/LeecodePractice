/*
Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) 
with the concatenation of the character and the number marking the count of the characters (length of the run). 
For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.
*/
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> mem(s.size(), vector<int>(k+1, -1));
        return dp(s, k, 0, ' ', 0, mem);
    }
private:
    int dp(string s, int k, int index, char last, int lastCount, vector<vector<int>> &mem){
        cout << index << "," << last << "," << k << endl;
        if(k<0) return INT_MAX;
        if(index==s.size()) return 0;
        if(mem[index][k]!=-1){
            cout << "mem " << mem[index][k] << endl;
            return mem[index][k];
        }
        int del = dp(s, k-1, index+1, last, lastCount, mem);
        int keep;
        if(s[index]==last){
            keep = dp(s, k, index+1, last, lastCount+1, mem)+(lastCount==1||lastCount==9||lastCount==99);
        }
        else{
            keep = dp(s, k, index+1, s[index], 1, mem)+1;
        }
        int res = min(del, keep);
        cout << index << "," << k << "," << res << endl;
        mem[index][k] = res;
        return res;
    }
};

int main(){
    Solution solution;

    string s;
    int k;

    /*s = "aaabcccd";
    k = 2;
    cout << solution.getLengthOfOptimalCompression(s, k) << endl;*/

    s = "aabbaa";
    k = 2;
    cout << solution.getLengthOfOptimalCompression(s, k) << endl;

    /*s = "aaaaaaaaaaa";
    k = 0;
    cout << solution.getLengthOfOptimalCompression(s, k) << endl;

    s = "abcdefghijklmnopqrstuvwxyz";
    k = 16;
    cout << solution.getLengthOfOptimalCompression(s, k) << endl;*/

    return 0;
}
