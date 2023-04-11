/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        unordered_map<char, int> sFreq;
        for(char c : t) tFreq[c]++;
        int count = 0;
        int left = 0, right = 0;
        string res = "";
        while(right<s.size()){
            sFreq[s[right]]++;
            if(sFreq[s[right]]<=tFreq[s[right]]){
                count++;
                if(count==t.size()){
                    while(tFreq[s[left]]==0 || sFreq[s[left]]>tFreq[s[left]]){
                        if(sFreq[s[left]]>tFreq[s[left]]) sFreq[s[left]]--;
                        left++;
                    }
                    if(res.empty() || right-left+1<res.size()){
                        res = s.substr(left, right-left+1);
                    }
                    while(left<right){
                        sFreq[s[left]]--;
                        if(sFreq[s[left]]<tFreq[s[left]]){
                            left++;
                            count--;
                            break;
                        }
                        left++;
                    }
                    while(left<right && tFreq[s[left]]==0) left++;
                }
            }
            right++;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string s;
    string t;

    s = "ADOBECODEBANC";
    t = "ABC";
    cout << solution.minWindow(s, t) << endl;

    s = "a";
    t = "a";
    cout << solution.minWindow(s, t) << endl;
    return 0;
}