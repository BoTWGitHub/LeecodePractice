#include <iostream>
#include <unordered_map>

using namespace std;

class Trie {
public:
    bool isWord = false;
    unordered_map<char, Trie*> children;
    Trie() {
        
    }
    void insert(string word) {
        Trie* node = this;
        for(char c : word){
            if(node->children.count(c)==0){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word){
            if(node->children.count(c)==0){
                return false;
            }
            node = node->children[c];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix){
            if(node->children.count(c)==0){
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};