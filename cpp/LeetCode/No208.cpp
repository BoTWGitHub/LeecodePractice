/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

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

int main(){
    Trie root = Trie();
    root.insert("apple");
    cout << root.search("apple") << endl;
    cout << root.search("app") << endl;
    cout << root.startsWith("app") << endl;
    root.insert("app");
    cout << root.search("app") << endl;
    Trie *node = &root;
    cout << node->children.size() << endl;
    root.insert("banana");
    cout << node->children.size() << endl;
    return 0;
}
