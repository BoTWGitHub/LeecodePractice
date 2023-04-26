/*
You are given two string arrays username and website and an integer array timestamp. 
All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.
The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.
Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        //add website to user (map str:vector<str>)
        unordered_map<string, set<pair<int, string>>> user_map;
        for(int i=0;i<username.size();i++){
            user_map[username[i]].insert({timestamp[i], website[i]});
        }
        
        //if website over 3 then permutation (return vector<str>)
        map<string, int> score_map;
        unordered_map<string, vector<string>> recover_map;
        int max_score = 0;
        for(pair<string, set<pair<int, string>>> element : user_map){
            if(element.second.size()==3){
                string temp;
                vector<string> rec;
                for(pair<int, string> p : element.second){
                    temp+=p.second;
                    rec.push_back(p.second);
                }
                score_map[temp]++;
                max_score = max(max_score, score_map[temp]);
                recover_map[temp] = rec;
            }
            else{
                vector<string> bucket;
                for(pair<int, string> p : element.second){
                    bucket.push_back(p.second);
                }
                set<vector<string>> candidate;
                vector<string> temp;
                pick3(bucket, temp, 0, candidate);
                for(vector<string> vs : candidate){
                    string t;
                    vector<string> rec;
                    for(string s : vs){
                        t+=s;
                        rec.push_back(s);
                    }
                    score_map[t]++;
                    max_score = max(max_score, score_map[t]);
                    recover_map[t] = rec;
                }
            }
        }
        //return max score lecicographically smallest pattern
        vector<vector<string>> results;
        for(auto it=score_map.begin();it!=score_map.end();it++){
            if(it->second==max_score){
                results.push_back(recover_map[it->first]);
            }
        }
        sort(results.begin(), results.end(), cmp);
        
        return results[0];
    }
private:
    void pick3(vector<string> &org, vector<string> &temp, int index, set<vector<string>> &res){
        if(temp.size()==3){
            res.insert(temp);
            return;
        }
        for(int i=index;i<org.size();i++){
            temp.push_back(org[i]);
            pick3(org, temp, i+1, res);
            temp.pop_back();
        }
    }
    static bool cmp(vector<string> v1, vector<string>v2){
        if(v1[0]!=v2[0]) return v1[0]<v2[0];
        if(v1[1]!=v2[1]) return v1[1]<v2[1];
        if(v1[2]!=v2[2]) return v1[2]<v2[2];
        return true;
    }
};

int main(void){
    Solution solution;
    
    vector<string> username = {"him","mxcmo","jejuvvtye","wphmqzn","uwlblbrkqv","flntc","esdtyvfs","nig","jejuvvtye","nig","mxcmo","flntc","nig","jejuvvtye","odmspeq","jiufvjy","esdtyvfs","mfieoxff","nig","flntc","mxcmo","qxbrmo"};
    vector<int> timestamp = {113355592,304993712,80831183,751306572,34485202,414560488,667775008,951168362,794457022,813255204,922111713,127547164,906590066,685654550,430221607,699844334,358754380,301537469,561750506,612256123,396990840,60109482};
    vector<string> website = {"k","o","o","nxpvmh","dssdnkv","kiuorlwdcw","twwginujc","evenodb","qqlw","mhpzoaiw","jukowcnnaz","m","ep","qn","wxeffbcy","ggwzd","tawp","gxm","pop","xipfkhac","weiujzjcy","x"};
    vector<string> res = solution.mostVisitedPattern(username, timestamp, website);
    printVector(res);
    //["m","kiuorlwdcw","xipfkhac"]
    return 0;
}