/*
Given n pairs of parentheses
, write a function to generate all combinations of well-formed parentheses.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        size = n;
        backtrack(n, n);
        return res;
    }
private:
    int size;
    vector<string> res;
    void backtrack(int left, int right, int count = 0, string temp = ""){
        if(temp.size()==size*2){
            res.push_back(temp);
            return;
        }
        if(count==0 && left>0){
            temp.push_back('(');
            backtrack(left-1, right, count+1, temp);
            temp.pop_back();
        }
        else{
            if(left>0){
                temp.push_back('(');
                backtrack(left-1, right, count+1, temp);
                temp.pop_back();
            }
            if(right>0){
                temp.push_back(')');
                backtrack(left, right-1, count-1, temp);
                temp.pop_back();
            }
        }
    }
};

int main(){
    Solution solution;
    
    int n=3;
    vector<string> res = solution.generateParenthesis(n);

    printVector<string>(res);
    return 0;
}
