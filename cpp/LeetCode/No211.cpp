/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
 void addWord(word) Adds word to the data structure, it can be matched later.
 bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
  word may contain dots '.' where dots can be matched with any letter.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class WordDictionary {
public:
    bool isWord = false;
    unordered_map<char, WordDictionary*> children;

    void addWord(string word) {
        WordDictionary* node = this;
        for(char c : word){
            if(node->children.count(c)==0) node->children[c] = new WordDictionary();
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchByNode(word, 0, this);
    }

    bool searchByNode(string& word, int index, WordDictionary* node){
        if(!node) return false;
        if(index==word.size()) return node->isWord;
        
        if(word[index]=='.'){
            for(auto [c, child] : node->children){
                if(searchByNode(word, index+1, child)) return true;
            }
        }
        else{
            if(node->children.count(word[index])){
                return searchByNode(word, index+1, node->children[word[index]]);
            }
        }
        return false;
    }
};

int main(void){
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl;
    cout << wd.search("bad") << endl;
    cout << wd.search(".ad") << endl;
    cout << wd.search("b..") << endl;
    cout << wd.search("b...") << endl;
    return 0;
}