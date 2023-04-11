/*
Given an array of strings wordsDict and two strings that already exist in the array word1 and word2
, return the shortest distance between the occurrence of these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> indexOf;
        for(int i=0;i<wordsDict.size();i++){
            indexOf[wordsDict[i]].push_back(i);
        }
        if(word1==word2){
            int res = INT_MAX;
            for(int i=1;i<indexOf[word1].size();i++){
                res = min(res, indexOf[word1][i]-indexOf[word1][i-1]);
            }
            return res;
        }
        else{
            queue<int> q;
            vector<bool> seen(wordsDict.size(), false);
            for(int i : indexOf[word1]){
                q.push(i);
                seen[i] = true;
            }
            int res = 0;
            while(!q.empty()){
                int size = q.size();
                res++;
                for(int i=0;i<size;i++){
                    int node = q.front();
                    q.pop();
                    if(node-1>=0 && !seen[node-1]){
                        seen[node-1] = true;
                        if(wordsDict[node-1]==word2) return res;
                        q.push(node-1);
                    }
                    if(node+1<wordsDict.size() && !seen[node+1]){
                        seen[node+1] = true;
                        if(wordsDict[node+1]==word2) return res;
                        q.push(node+1);
                    }
                }
            }
            return -1;
        }
    }
};

int main(void){
    Solution solution;
    vector<string> wordsDict;
    string word1;
    string word2;

    wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    word1 = "makes";
    word2 = "coding";
    cout << solution.shortestWordDistance(wordsDict, word1, word2) << endl;

    wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    word1 = "makes";
    word2 = "makes";
    cout << solution.shortestWordDistance(wordsDict, word1, word2) << endl;
    return 0;
}