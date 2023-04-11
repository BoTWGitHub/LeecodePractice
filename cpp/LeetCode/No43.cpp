/*
Given two non-negative integers num1 and num2 represented as strings
, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string res = "0";
        for(int i=num2.size()-1;i>=0;i--){
            string temp = "";
            int c = 0;
            int j=num1.size()-1;
            while(j>=0 || c){
                int m = 0;
                if(j>=0){
                    m = (num2[i]-'0')*(num1[j]-'0');
                    j--;
                }
                m+=c;
                c=m/10;
                m%=10;
                temp.insert(temp.begin(), '0'+m);
            }
            for(int k=0;k<num2.size()-1-i;k++) temp+='0';
            res = add(res, temp);
        }
        return res;
    }
private:
    string add(string num1, string num2){
        int i1 = num1.size()-1, i2 = num2.size()-1;
        int c = 0;
        string res = "";
        while(i1>=0 || i2>=0 || c){
            int s = 0;
            if(i1>=0){
                s+=num1[i1]-'0';
                i1--;
            }
            if(i2>=0){
                s+=num2[i2]-'0';
                i2--;
            }
            s+=c;
            c=s/10;
            s%=10;
            res.insert(res.begin(), '0'+s);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string num1, num2;

    num1 = "2";
    num2 = "3";
    cout << solution.multiply(num1, num2) << endl;

    num1 = "123";
    num2 = "456";
    cout << solution.multiply(num1, num2) << endl;

    num1 = "1999";
    num2 = "9111";
    cout << solution.multiply(num1, num2) << endl;
    return 0;
}