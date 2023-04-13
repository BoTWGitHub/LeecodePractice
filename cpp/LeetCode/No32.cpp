/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> sk;
        sk.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') sk.push(i);
            else{
                if(!sk.empty()) sk.pop();
                if(sk.empty()) sk.push(i);
                else res = max(res, i-sk.top());
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "(()";
    cout << solution.longestValidParentheses(s) << endl;

    s = ")()())";
    cout << solution.longestValidParentheses(s) << endl;

    s = "";
    cout << solution.longestValidParentheses(s) << endl;
    return 0;
}