/*
You are given a list of equivalent string pairs synonyms where synonyms[i] = [si, ti] indicates that si and ti are equivalent strings. 
You are also given a sentence text.

Return all possible synonymous sentences sorted lexicographically.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class UnionFind{
public:
    UnionFind(int size){
        root = vector<int>(size);
        rank = vector<int>(size, 1);
        for(int i=0;i<size;i++) root[i] = i;
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]) root[rx] = ry;
            else if(rank[rx]>rank[ry]) root[ry] = rx;
            else{
                root[rx] = ry;
                rank[ry]++;
            }
        }
    }
private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    Solution(){
        m.clear();
        replace.clear();
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        int count = 0;
        for(vector<string> v : synonyms){
            if(m.count(v[0])==0) m[v[0]]=count++;
            if(m.count(v[1])==0) m[v[1]]=count++;
        }
        UnionFind uf(count);
        for(vector<string> v : synonyms) uf.connect(m[v[0]], m[v[1]]);
        for(auto p : m) replace[uf.find(p.second)].push_back(p.first);
        
        vector<string> res;
        vector<string> org = split(text);
        backtrack(org, 0, uf, res);
        sort(res.begin(), res.end());
        return res;
    }
private:
    unordered_map<string, int> m;
    unordered_map<int, vector<string>> replace;

    vector<string> split(string s){
        istringstream ss(s);
        string temp;
        vector<string> res;
        while(ss>>temp) res.push_back(temp);
        return res;
    }

    void backtrack(vector<string> &org, int index, UnionFind &uf, vector<string> &res){
        if(index==org.size()){
            string temp = "";
            for(string s : org) temp+=(s+" ");
            temp.pop_back();
            res.push_back(temp);
            return;
        }

        if(m.count(org[index])){
            vector<string> rep = replace[uf.find(m[org[index]])];
            for(string r : rep){
                string temp = org[index];
                org[index] = r;
                backtrack(org, index+1, uf, res);
                org[index] = temp;
            }
        }
        else{
            backtrack(org, index+1, uf, res);
        }
    }
};

int main(void){
    Solution solution;
    vector<vector<string>> synonyms;
    string text;
    vector<string> res;

    solution = Solution();
    synonyms = {{"happy","joy"},{"sad","sorrow"},{"joy","cheerful"}};
    text = "I am happy today but was sad yesterday";
    res = solution.generateSentences(synonyms, text);
    printVector(res);

    solution = Solution();
    synonyms = {{"happy","joy"},{"cheerful","glad"}};
    text = "I am happy today but was sad yesterday";
    res = solution.generateSentences(synonyms, text);
    printVector(res);
    return 0;
}