/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> mem(n, vector<int>(5, -1));
        return dp(n, 0, -1, mem);
    }
private:
    int mod = 7+pow(10, 9);
    int dp(int n, int index, int last, vector<vector<int>> &mem){
        if(index==n) return 1;
        if(last!=-1 && mem[index][last]!=-1) return mem[index][last];

        int res = 0;
        switch(last){
            case 0: //a
                res = (res+dp(n, index+1, 1, mem))%mod;
                break;
            case 1: //e
                res = (res+dp(n, index+1, 0, mem))%mod;
                res = (res+dp(n, index+1, 2, mem))%mod;
                break;
            case 2: //i
                for(int i=0;i<5;i++){
                    if(i==2) continue;
                    res = (res+dp(n, index+1, i, mem))%mod;
                }
                break;
            case 3: //o
                res = (res+dp(n, index+1, 2, mem))%mod;
                res = (res+dp(n, index+1, 4, mem))%mod;
                break;
            case 4: //u
                res = (res+dp(n, index+1, 0, mem))%mod;
                break;
            case -1: //first letter
                for(int i=0;i<5;i++){
                    res+=dp(n, index+1, i, mem);
                    res%=mod;
                }
                break;
        }
        if(last!=-1) mem[index][last] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    int n;

    n=1;
    cout << solution.countVowelPermutation(n) << endl;

    n=2;
    cout << solution.countVowelPermutation(n) << endl;

    n=5;
    cout << solution.countVowelPermutation(n) << endl;

    n=144;
    cout << solution.countVowelPermutation(n) << endl;

    return 0;
}