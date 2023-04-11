/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Given an integer, convert it to a roman numeral.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";

        while(num>=1000){
            res+='M';
            num-=1000;
        }
        
        res+=transToRoman(num/100, 'C', 'D', 'M');
        num%=100;
        
        res+=transToRoman(num/10, 'X', 'L', 'C');
        num%=10;

        res+=transToRoman(num, 'I', 'V', 'X');

        return res;
    }
private:
    string transToRoman(int digit, char one, char five, char ten){
        string res = "";
        if(digit==9){
            res+=one;
            res+=ten;
        }
        else if(digit>=5){
            res+=five;
            for(int i=0;i<digit-5;i++){
                res+=one;
            }
        }
        else if(digit==4){
            res+=one;
            res+=five;
        }
        else{
            for(int i=0;i<digit;i++){
                res+=one;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;

    cout << solution.intToRoman(3) << endl;
    cout << solution.intToRoman(58) << endl;
    cout << solution.intToRoman(1994) << endl;
    cout << solution.intToRoman(3999) << endl;
    return 0;
}
