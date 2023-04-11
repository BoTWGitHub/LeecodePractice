/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution { //KMP algorithm
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m>n) return -1;
        vector<int> pre(m, 0);
        int i = 0;
        int j = 1;
        //make the prefix match table
        while(j<m){
            if(needle[j]==needle[i]) pre[j++] = ++i;
            else{
                if(i==0) pre[j++] = i;
                else i = pre[i-1];
            }
        }

        //matching
        i = 0;
        j = 0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==m) return i-m;
            }
            else{
                if(j==0) i++;
                else j = pre[j-1];
            }
        }

        return -1;
    }
};

int main(void){
    Solution solution;
    string haystack;
    string needle;

    haystack = "sadbutsad";
    needle = "sad";
    cout << solution.strStr(haystack, needle) << endl;

    haystack = "leetcode";
    needle = "leeto";
    cout << solution.strStr(haystack, needle) << endl;

    haystack = "onionionskys";
    needle = "onions";
    cout << solution.strStr(haystack, needle) << endl;

    haystack = "abcdabfabcdabeeabcdabeeabcdabeeabf";
    needle = "abcdabeeabf";
    cout << solution.strStr(haystack, needle) << endl;

    haystack = "aabaaabaaac";
    needle = "aabaaac";
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}