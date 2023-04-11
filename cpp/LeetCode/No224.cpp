/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> sk;
        string temp = "";
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]) || s[i]=='+' || s[i]=='-') temp.push_back(s[i]);
            else if(s[i]=='(' && temp.size()>0){
                sk.push(temp);
                temp.clear();
            }
            else if(s[i]==')'){
                string num = helper(temp);
                if(!sk.empty()){
                    temp = sk.top();
                    sk.pop();
                    if(num[0]=='-'){
                        if(temp.back()=='+'){
                            temp.pop_back();
                            temp+=num;
                        }
                        else{
                            temp.pop_back();
                            num[0] = '+';
                            temp+=num;
                        }
                    }
                    else{
                        temp+=num;
                    }
                }
                else{
                    temp = num;
                }
            }
        }
        return stoi(helper(temp));
    }
private:
    string helper(string s){
        int res = 0;
        bool neg = false;
        string temp;
        for(int i=0;i<s.size();i++){
            if(i==0 && !isdigit(s[i])){
                if(s[i]=='-') neg = true;
            }
            else if(isdigit(s[i])){
                temp.push_back(s[i]);
            }
            else{
                if(neg) res-=stoi(temp);
                else res+=stoi(temp);
                temp.clear();
                if(s[i]=='+') neg = false;
                else neg = true;
            }
        }
        if(temp.size()>0){
            if(neg) res-=stoi(temp);
            else res+=stoi(temp);
        }
        return to_string(res);
    }
};

int main(void){
    Solution solution;
    string s;

    s = "1 + 1";
    cout << solution.calculate(s) << endl;

    s = " 2-1 + 2 ";
    cout << solution.calculate(s) << endl;

    s = "(1+(4+5+2)-3)+(6+8)";
    cout << solution.calculate(s) << endl;

    s = "(5-(1+(5)))";
    cout << solution.calculate(s) << endl;

    s = "-(-2)+4";
    cout << solution.calculate(s) << endl;
    return 0;
}