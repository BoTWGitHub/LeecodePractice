/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells
, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Debug\VectorDebug.h"

using namespace std;

struct Trie{
    string word = "";
    unordered_map<char, Trie*> children;
    void insert(string word){
        Trie *node = this;
        for(char c : word){
            if(node->children.count(c)==0){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        row = board.size();
        col = board[0].size();

        Trie* root = new Trie();
        for(string word : words){
            root->insert(word);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(root->children.count(board[i][j])){
                    backtrack(board, root, i, j, res);
                }
            }
        }
        return res;
    }
private:
    int row;
    int col;
    const vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; 
    void backtrack(vector<vector<char>>& board, Trie* node, int x, int y, vector<string> &res){
        cout << x << "," << y << endl;
        char c = board[x][y];
        board[x][y] = ' ';
        Trie* cur = node->children[c];
        if(cur->word!=""){
            cout << "insert " << cur->word << endl;
            res.push_back(cur->word);
            cur->word = "";
        }

        for(vector<int> dir : dirs){
            int nx = x+dir[0];
            int ny = y+dir[1];
            if(nx>=0 && nx<row && ny>=0 && ny<col){
                if(cur->children.count(board[nx][ny])){
                    backtrack(board, cur, nx, ny, res);
                }
            }
        }
        board[x][y] = c;
        if(cur->children.empty()){
            node->children.erase(c);
        }
    }
};

int main(){
    Solution solution;

    vector<vector<char>> board = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'},
                                  {'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = solution.findWords(board, words);
    printVector(res);

    return 0;
}
