/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters
, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            while(left<s.size() && !isAlphanumeric(s[left])) left++;
            while(right>=0 && !isAlphanumeric(s[right])) right--;
            if(left>=right) break;
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
private:
    bool isAlphanumeric(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }
};

int main(){
    return 0;
}
