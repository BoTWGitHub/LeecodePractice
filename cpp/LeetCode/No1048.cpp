/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. 
A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){
            return s1.size()<s2.size();
        });
        vector<vector<int>> mem(words.size(), vector<int>(words.size(), -1));
        return dp(words, 0, -1, mem);
    }
private:
    int dp(vector<string>& words, int index, int last, vector<vector<int>>& mem){
        if(index==words.size()) return 0;
        if(last!=-1 && mem[index][last]!=-1) return mem[index][last];

        int res = 0;
        if(last==-1){
            res = max(dp(words, index+1, index, mem)+1, dp(words, index+1, last, mem));
        }
        else{
            res = dp(words, index+1, last, mem);
            if(words[index].size()==words[last].size()+1){
                int j = 0;
                for(int i=0;i<words[index].size();i++){
                    if(j<words[last].size() && words[index][i]==words[last][j]) j++;
                }
                if(j==words[last].size()){
                    res = max(res, dp(words, index+1, index, mem)+1);
                }
            }
        }
        if(last!=-1) mem[index][last] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<string> words;

    words = {"a","b","ba","bca","bda","bdca"};
    cout << solution.longestStrChain(words) << endl;

    words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout << solution.longestStrChain(words) << endl;

    words = {"abcd","dbqca"};
    cout << solution.longestStrChain(words) << endl;
    return 0;
}