/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. 
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::string res = "";
        std::stack<char> sk;
        for(char c : s){
            if(c==']'){
                std::string temp = "";
                while(sk.top()!='['){
                    temp.insert(temp.begin(), sk.top());
                    sk.pop();
                }
                sk.pop();

                std::string times = "";
                while(!sk.empty() && isdigit(sk.top())){
                    times.insert(times.begin(), sk.top());
                    sk.pop();
                }
                for(int i=0;i<stoi(times);i++){
                    for(char c : temp){
                        sk.push(c);
                    }
                }
            }
            else{
                sk.push(c);
            }
        }
        while(!sk.empty()){
            res.insert(res.begin(), sk.top());
            sk.pop();
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::string s;

    s = "3[a]2[bc]";
    std::cout << solution.decodeString(s) << std::endl;

    s = "3[a2[c]]";
    std::cout << solution.decodeString(s) << std::endl;

    s = "2[abc]3[cd]ef";
    std::cout << solution.decodeString(s) << std::endl;
    return 0;
}