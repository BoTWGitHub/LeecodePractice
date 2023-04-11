/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s, 0, res);
        return res;
    }
private:
    void backtrack(string& s, int index, vector<string>& res){
        if(index==s.size()){
            res.push_back(s);
            return;
        }
        if(isdigit(s[index])){
            backtrack(s, index+1, res);
        }
        else{
            backtrack(s, index+1, res);
            if(s[index]>='a' && s[index]<='z'){
                char temp = s[index];
                s[index] = 'A' + (s[index] - 'a');
                backtrack(s, index+1, res);
                s[index] = temp;
            }
            else{
                char temp = s[index];
                s[index] = 'a' + (s[index] - 'A');
                backtrack(s, index+1, res);
                s[index] = temp;
            }
        }
    }
};

int main(void){
    Solution solution;
    string s;
    vector<string> res;

    s = "a1b2";
    res = solution.letterCasePermutation(s);
    printVector(res);

    s = "3z4";
    res = solution.letterCasePermutation(s);
    printVector(res);
    return 0;
}