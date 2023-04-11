/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i] = (s[i]=='0');
                continue;
            }
            if(s[i]=='0') prefix[i] = prefix[i-1]+1;
            else prefix[i] = prefix[i-1];
        }
        int res = min(prefix.back(), n-prefix.back());
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                res = min(res, prefix.back()-prefix[i]+count);
                count++;
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string s;

    s = "00110";
    cout << solution.minFlipsMonoIncr(s) << endl;

    s = "010110";
    cout << solution.minFlipsMonoIncr(s) << endl;

    s = "00011000";
    cout << solution.minFlipsMonoIncr(s) << endl;

    s = "10101111011011111011001011011011010110100111000100110001011011011011101101001000010100011101100000101100000100010110111001011111100101000010111000001100001100011011001011100110000001101011111100111111";
    cout << solution.minFlipsMonoIncr(s) << endl;
    return 0;
}