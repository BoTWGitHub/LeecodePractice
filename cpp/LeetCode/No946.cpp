/*
Given two integer arrays pushed and popped each with distinct values
, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int i1 = 0, i2 = 0;
        while(i2<popped.size()){
            while((sk.empty() || sk.top()!=popped[i2]) && i1<pushed.size()){
                sk.push(pushed[i1++]);
            }
            while(!sk.empty() && sk.top()==popped[i2] && i2<popped.size()){
                sk.pop();
                i2++;
            }
            if(i1==pushed.size() && !sk.empty()) return false;
        }
        return true;
    }
};

int main(void){
    Solution solution;
    vector<int> pushed;
    vector<int> popped;

    pushed = {1,2,3,4,5};
    popped = {4,5,3,2,1};
    cout << solution.validateStackSequences(pushed, popped) << endl;

    pushed = {1,2,3,4,5};
    popped = {4,3,5,1,2};
    cout << solution.validateStackSequences(pushed, popped) << endl;
    return 0;
}