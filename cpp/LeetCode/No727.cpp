/*
Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

If there is no such window in s1 that covers all characters in s2, return the empty string "". 
If there are multiple such minimum-length windows, return the one with the left-most starting index.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string s1, std::string s2) {
        std::vector<std::vector<int>> mem(s1.size(), std::vector<int>(s2.size(), -1));
        int len = INT_MAX;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[0]){
                len = std::min(len, dp(s1, s2, i, 0, mem));
            }
        }
        if(len<=s1.size()){
            for(int i=0;i<s1.size();i++){
                if(mem[i][0]==len) return s1.substr(i, len);
            }
        }
        return "";
    }
private:
    int dp(std::string& s1, std::string& s2, int i1, int i2, std::vector<std::vector<int>>& mem){
        if(i2==s2.size()) return 0;
        if(i1==s1.size()) return s1.size()+s2.size();
        if(mem[i1][i2]!=-1) return mem[i1][i2];

        int res;
        if(s1[i1]==s2[i2]){
            res = dp(s1, s2, i1+1, i2+1, mem)+1;
        }
        else{
            res = dp(s1, s2, i1+1, i2, mem)+1;
        }
        return mem[i1][i2] = res;
    }
};

int main(void){
    Solution solution;
    std::string s1;
    std::string s2;

    s1 = "abcdebdde";
    s2 = "bde";
    std::cout << solution.minWindow(s1, s2) << std::endl;

    s1 = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl";
    s2 = "u";
    std::cout << solution.minWindow(s1, s2) << std::endl;

    s1 = "aa";
    s2 = "aa";
    std::cout << solution.minWindow(s1, s2) << std::endl;
    return 0;
}