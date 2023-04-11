/*
Given a string s and a dictionary of strings wordDict
, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
#include <iostream>
#include <string>
#include <vector>
#include "Debug\Trie.h"
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        for(string word : wordDict){
            root->insert(word);
        }
        vector<bool> mem(s.size(), true);
        return dp(s, 0, root, mem);
    }
private:
    bool dp(string &s, int index, Trie* root, vector<bool> &mem){
        if(index==s.size()) return true;
        if(!mem[index]) return false;
        string temp = "";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(root->search(temp) && dp(s, i+1, root, mem)) return true;
            if(!root->startsWith(temp)){
                mem[index] = false;
                return false;
            }
        }
        mem[index] = false;
        return false;
    }
};

int main(){
    Solution solution;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << solution.wordBreak(s, wordDict) << endl;

    s = "applepenapple";
    wordDict = {"apple","pen"};
    cout << solution.wordBreak(s, wordDict) << endl;

    s = "catsandog";
    wordDict = {"cats","dog","sand","and","cat"};
    cout << solution.wordBreak(s, wordDict) << endl;

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << solution.wordBreak(s, wordDict) << endl;

    return 0;
}
