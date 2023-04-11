/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string, int> count;
        for(string word : words){
            count[word]++;
        }
        bool odd = false;
        for(pair<string, int> p : count){
            if(p.first[0]==p.first[1]){
                res+=(p.second/2*4);
                if(!odd && p.second%2){
                    odd = true;
                    res+=2;
                }
            }
            else{
                string rev = {p.first[1], p.first[0]};
                if(count.count(rev)){
                    res+=min(count[p.first], count[rev])*4;
                    count.erase(rev);
                }
            }
        }

        return res;
    }
};

int main(void){
    Solution solution;
    vector<string> words;

    words = {"lc","cl","gg"};
    cout << solution.longestPalindrome(words) << endl;

    words = {"ab","ty","yt","lc","cl","ab"};
    cout << solution.longestPalindrome(words) << endl;

    words = {"cc","ll","xx"};
    cout << solution.longestPalindrome(words) << endl;

    return 0;
}