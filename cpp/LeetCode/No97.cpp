/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration 
where s and t are divided into n and m non-empty substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()==0 && s2.size()==0 && s3.size()==0) return true;
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<vector<bool>>> mem(s1.size()+1, vector<vector<bool>>(s2.size()+1, vector<bool>(s3.size(), true)));
        return dp(s1, s2, s3, 0, 0, 0, mem);
    }
private:
    bool dp(string s1, string s2, string s3, int i1, int i2, int i3, vector<vector<vector<bool>>> &mem){
        if(i3==s3.size()) return true;
        if(mem[i1][i2][i3]==false) return false;
        bool res = false;
        if(i1<s1.size() && s1[i1]==s3[i3] && i2<s2.size() && s2[i2]==s3[i3]){
            if(dp(s1, s2, s3, i1+1, i2, i3+1, mem)) return true;
            if(dp(s1, s2, s3, i1, i2+1, i3+1, mem)) return true;
        }
        else if(i1<s1.size() && s1[i1]==s3[i3]){
            if(dp(s1, s2, s3, i1+1, i2, i3+1, mem)) return true;
        }
        else if(i2<s2.size() && s2[i2]==s3[i3]){
            if(dp(s1, s2, s3, i1, i2+1, i3+1, mem)) return true;
        }
        return mem[i1][i2][i3] = false;
    }
};

int main(void){
    Solution solution;
    string s1, s2, s3;

    s1="aabcc";
    s2="dbbca";
    s3="aadbbcbcac";
    cout << solution.isInterleave(s1, s2, s3) << endl;

    s1="aabcc";
    s2="dbbca";
    s3="aadbbbaccc";
    cout << solution.isInterleave(s1, s2, s3) << endl;

    s1="";
    s2="";
    s3="";
    cout << solution.isInterleave(s1, s2, s3) << endl;

    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    cout << solution.isInterleave(s1, s2, s3) << endl;
    
    return 0;
}