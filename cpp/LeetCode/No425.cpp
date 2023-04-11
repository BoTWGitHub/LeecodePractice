/*
Given an array of unique strings words, return all the word squares you can build from words. 
The same word from words can be used multiple times. 
You can return the answer in any order.

A sequence of strings forms a valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Debug\VectorDebug.h"

using namespace std;

struct Trie{
    bool isWord = false;
    unordered_map<char, Trie*> children;
    void insert(string word){
        Trie* node = this;
        for(char c : word){
            if(node->children.count(c)==0){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie* root = new Trie();
        for(string word : words){
            root->insert(word);
        }
    }
private:
    void backtrack(int step, Trie* node, vector<string> &temp, vector<vector<string>> &res){
        if(step==4){
            res.push_back(temp);
            return;
        }
    }
};

int main(){
    Solution solution;

    vector<string> words = {"area","lead","wall","lady","ball"};
    vector<vector<string>> res = solution.wordSquares(words);
    print2DVector(res);
    return 0;
}
