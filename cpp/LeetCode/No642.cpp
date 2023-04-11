/*
Design a search autocomplete system for a search engine. 
Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n 
where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. 
For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

 - The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
 - The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). 
   If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
 - If less than 3 hot sentences exist, return as many as you can.
 - When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Implement the AutocompleteSystem class:

 - AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
 - List<String> input(char c) This indicates that the user typed the character c.
    - Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
    - Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. 
      If there are fewer than 3 matches, return them all.
*/
#include <iostream>
#include <unordered_map>
#include <queue>
#include "Debug\VectorDebug.h"
using namespace std;

class Trie{
public:
    int index = -1;
    vector<int> startWith;
    unordered_map<char, Trie*> children;
    void insert(string& word, int index){
        Trie* node = this;
        for(char c : word){
            if(node->children.count(c)==0) node->children[c] = new Trie();
            node = node->children[c];
            node->startWith.push_back(index);
        }
        node->index = index;
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        this->sentences = sentences;
        this->times = times;
        for(int i=0;i<sentences.size();i++){
            root->insert(sentences[i], i);
        }
        cur = root;
    }
    
    vector<string> input(char c) {
        vector<string> res;
        if(c=='#'){
            if(cur && cur->index!=-1){
                times[cur->index]++;
            }
            else{
                sentences.push_back(tmp);
                times.push_back(1);
                root->insert(tmp, times.size()-1);
            }
            tmp = "";
            cur = root;
        }
        else{
            tmp.push_back(c);
            if(cur && cur->children.count(c)){
                cur = cur->children[c];
                vector<int> startWith = cur->startWith;
                auto cmp = [](const auto& p1, const auto& p2){
                    if(p1.second!=p2.second) return p1.second>p2.second;
                    return p1.first<p2.first;
                };
                priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> heap(cmp);
                for(int i : startWith){
                    heap.push({sentences[i], times[i]});
                    if(heap.size()>3) heap.pop();
                }
                while(!heap.empty()){
                    res.insert(res.begin(), heap.top().first);
                    heap.pop();
                }
            }
            else{
                cur = nullptr;
            }
        }
        return res;
    }
private:
    Trie* root;
    Trie* cur;
    string tmp = "";
    vector<string> sentences;
    vector<int> times;
};

int main(void){
    vector<string> sentences = {"i love you", "island", "iroman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem acs(sentences, times);
    vector<string> res;

    res = acs.input('i');
    printVector(res);
    res = acs.input(' ');
    printVector(res);
    res = acs.input('a');
    printVector(res);
    res = acs.input('#');
    printVector(res);

    res = acs.input('i');
    printVector(res);
    res = acs.input(' ');
    printVector(res);
    res = acs.input('a');
    printVector(res);
    res = acs.input('#');
    printVector(res);
    return 0;
}