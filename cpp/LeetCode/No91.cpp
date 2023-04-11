/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). 
For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> mem;
        return recursive(s, 0, mem);
    }
private:
    int recursive(string &s, int start, unordered_map<int, int> &mem){
        if(mem.find(start)!=mem.end()){
            return mem[start];
        }

        if(start==s.size()){
            return 1;
        }
        
        if(s[start]=='0'){
            return 0;
        }

        if(start==s.size()-1){
            return 1;
        }

        int ans = recursive(s, start+1, mem);
        if(start+1<s.size() && (s[start]=='1' || (s[start]=='2' && s[start+1]>='0' && s[start+1]<'7'))){
            ans+=recursive(s, start+2, mem);
        }

        mem[start] = ans;

        return ans;
    }
};

int main(void){
    Solution solution;
    string s = "111111111111111111111111111111111111111111111";
    cout << solution.numDecodings(s) << endl;
    return 0;
}