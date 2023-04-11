/*
There is a new alien language that uses the English alphabet. 
However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary
, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. 
If there is no solution, return "". 
If there are multiple solutions, return any of them.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> inDegree;
        unordered_map<char, vector<char>> ajList;
        set<pair<char, char>> edges;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                int index = 0;
                while(index<words[i].size() && index<words[j].size() && words[i][index]==words[j][index]){
                    if(inDegree.count(words[i][index])==0){
                        inDegree[words[i][index]] = 0;
                    }
                    index++;
                }
                if(index<words[i].size() && index==words[j].size()) return "";
                if(index==words[i].size()) continue;
                edges.insert({words[i][index], words[j][index]});
            }
        }

        for(pair<char, char> edge : edges){
            if(inDegree.count(edge.first)==0) inDegree[edge.first] = 0;
            inDegree[edge.second]++;
            ajList[edge.first].push_back(edge.second);
        }

        string res = "";
        queue<char> q;
        for(auto p : inDegree){
            if(p.second==0) q.push(p.first);
        }

        while(!q.empty()){
            char node = q.front();
            q.pop();
            res.push_back(node);
            for(char neighbor : ajList[node]){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0) q.push(neighbor);
            }
        }
        if(res.size()!=ajList.size()) return "";
        return res;
    }
};

int main(void){
    Solution solution;
    vector<string> words;

    words = {"wrt","wrf","er","ett","rftt"};
    cout << solution.alienOrder(words) << endl;

    words = {"z","x"};
    cout << solution.alienOrder(words) << endl;

    words = {"z","x","z"};
    cout << solution.alienOrder(words) << endl;
    return 0;
}