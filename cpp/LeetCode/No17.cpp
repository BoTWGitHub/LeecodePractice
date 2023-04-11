/*
Given a string containing digits from 2-9 inclusive
, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()>0)
            backtrack(res, digits);
        return res;
    }
private:
    vector<string> table{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(vector<string> &res, string &digits, string temp = "", int step = 0){
        if(step==digits.size()){
            res.push_back(temp);
            return;
        }
        int index = digits[step] - '2';
        for(char c : table[index]){
            temp.push_back(c);
            backtrack(res, digits, temp, step+1);
            temp.pop_back();
        }
    }
};

int main(){
    Solution solution;

    string digits = "";
    vector<string> res;
    res = solution.letterCombinations(digits);

    printVector<string>(res);

    return 0;
}
