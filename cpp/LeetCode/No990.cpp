/*
You are given an array of strings equations that represent relationships between variables 
where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Debug\UnionFind.h"
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        vector<string> notEqual;
        for(string equation : equations){
            if(equation[1]=='!'){
                notEqual.push_back(equation);
                continue;
            }
            else{
                uf.connect(equation[0]-'a', equation[3]-'a');
            }
        }
        for(string equation : notEqual){
            if(uf.find(equation[0]-'a')==uf.find(equation[3]-'a')) return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<string> equations;

    equations = {"a==b","b!=a"};
    cout << solution.equationsPossible(equations) << endl;

    equations = {"b==a","a==b"};
    cout << solution.equationsPossible(equations) << endl;
    return 0;
}
