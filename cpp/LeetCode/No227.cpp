/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> sk;
        string temp = "";
        int last = 1;
        bool mul = false;
        bool div = false;
        bool neg = false;
        for(char c : s){
            if(isdigit(c)){
                temp.push_back(c);
            }
            else if(c=='+'){
                int num = stoi(temp);
                temp.clear();
                if(mul){
                    mul = false;
                    num*=last;
                    last = 1;
                }
                if(div){
                    div = false;
                    num = last/num;
                    last = 1;
                }
                if(neg){
                    neg = false;
                    num*=-1;
                }
                sk.push(num);
            }
            else if(c=='-'){
                int num = stoi(temp);
                temp.clear();
                if(mul){
                    mul = false;
                    num*=last;
                    last = 1;
                }
                if(div){
                    div = false;
                    num = last/num;
                    last = 1;
                }
                if(neg){
                    num*=-1;
                }
                neg = true;
                sk.push(num);
            }
            else if(c=='*'){
                int num = stoi(temp);
                temp.clear();
                if(div){
                    div = false;
                    num = last/num;
                }
                if(mul){
                    num = last*num;
                }
                mul = true;
                last = num;
            }
            else if(c=='/'){
                int num = stoi(temp);
                temp.clear();
                if(div){
                    num = last/num;
                }
                if(mul){
                    mul=false;
                    num = last*num;
                }
                div = true;
                last = num;
            }
        }
        int num = stoi(temp);
        temp.clear();
        if(mul){
            num*=last;
        }
        if(div){
            num = last/num;
        }
        if(neg){
            num*=-1;
        }
        sk.push(num);
        int res = 0;
        while(!sk.empty()){
            res+=sk.top();
            sk.pop();
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "3+2*2";
    cout << solution.calculate(s) << endl;

    s = "3/2";
    cout << solution.calculate(s) << endl;

    s = " 3+5 / 2 ";
    cout << solution.calculate(s) << endl;

    s = " 0-3 ";
    cout << solution.calculate(s) << endl;
    return 0;
}