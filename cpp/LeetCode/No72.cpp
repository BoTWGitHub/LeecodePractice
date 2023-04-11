/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

 - Insert a character
 - Delete a character
 - Replace a character
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0, mem);
    }
private:
    int dp(string& word1, string& word2, int i1, int i2, vector<vector<int>>& mem){
        if(i1==word1.size()) return word2.size()-i2;
        if(i2==word2.size()) return word1.size()-i1;
        if(mem[i1][i2]!=-1) return mem[i1][i2];

        int res;
        if(word1[i1]==word2[i2]) res = dp(word1, word2, i1+1, i2+1, mem);
        else{
            int insert = dp(word1, word2, i1, i2+1, mem)+1;
            int deletion = dp(word1, word2, i1+1, i2, mem)+1;
            int replace = dp(word1, word2, i1+1, i2+1, mem)+1;
            res = min(insert, min(deletion, replace));
        }
        return mem[i1][i2] = res;
    }
};

int main(void){
    Solution solution;
    string word1;
    string word2;

    word1 = "horse";
    word2 = "ros";
    cout << solution.minDistance(word1, word2) << endl;

    word1 = "intention";
    word2 = "execution";
    cout << solution.minDistance(word1, word2) << endl;
    return 0;
}