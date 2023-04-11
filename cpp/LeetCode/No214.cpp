/*
You are given a string s. 
You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i=n/2;i>=0;i--){
            int left = i-1, right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            if(left==-1){
                for(int j=n-1;j>=right;j--){
                    res.push_back(s[j]);
                }
                break;
            }
            else if(i>0 && s[i-1]==s[i]){
                left = i-2;
                right = i+1;
                while(left>=0 && right<n && s[left]==s[right]){
                    left--;
                    right++;
                }
                if(left==-1){
                    for(int j=n-1;j>=right;j--){
                        res.push_back(s[j]);
                    }
                    break;
                }
            }
        }
        return res+s;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "aacecaaa";
    cout << solution.shortestPalindrome(s) << endl;

    s = "abacecaaa";
    cout << solution.shortestPalindrome(s) << endl;

    s = "abcd";
    cout << solution.shortestPalindrome(s) << endl;

    s = "babbbabbaba";
    cout << solution.shortestPalindrome(s) << endl;
    return 0;
}