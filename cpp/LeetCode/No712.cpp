/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> mem(s1.size(), vector<int>(s2.size(), -1));
        return dp(s1, s2, 0, 0, mem);
    }
private:
    int dp(string& s1, string& s2, int i1, int i2, vector<vector<int>>& mem){
        if(i1==s1.size()){
            int temp = 0;
            for(int i=i2;i<s2.size();i++) temp+=s2[i];
            return temp;
        }
        if(i2==s2.size()){
            int temp = 0;
            for(int i=i1;i<s1.size();i++) temp+=s1[i];
            return temp;
        }
        if(mem[i1][i2]!=-1) return mem[i1][i2];

        int res = 0;
        if(s1[i1]==s2[i2]){
            res = dp(s1, s2, i1+1, i2+1, mem);
        }
        else{
            res = min(dp(s1, s2, i1+1, i2, mem)+s1[i1], dp(s1, s2, i1, i2+1, mem)+s2[i2]);
        }
        return mem[i1][i2] = res;
    }
};

int main(void){
    Solution solution;
    string s1;
    string s2;

    s1 = "sea";
    s2 = "eat";
    cout << solution.minimumDeleteSum(s1, s2) << endl;

    s1 = "delete";
    s2 = "leet";
    cout << solution.minimumDeleteSum(s1, s2) << endl;
    return 0;
}