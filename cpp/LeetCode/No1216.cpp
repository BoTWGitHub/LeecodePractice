/*
Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        return true;
    }
private:
    bool isPalimdrome(string s, unordered_set<int> skip){
        int left = 0, right = s.size()-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
            while(skip.count(left) && left<s.size()) left++;
            if(skip.count(right) && right>=0) right--;
        }
        return true;
    }
    bool dp(string s, int k, int index, vector<vector<bool>>& mem){
        
    }
};

int main(void){
    Solution solution;
    string s;
    int k;

    s = "abcdeca";
    k = 2;
    cout << solution.isValidPalindrome(s, k) << endl;

    s = "abbababa";
    k = 1;
    cout << solution.isValidPalindrome(s, k) << endl;

    s = "bacabaaa";
    k = 2;
    cout << solution.isValidPalindrome(s, k) << endl;
    return 0;
}