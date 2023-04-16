/*
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target
, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words
, you can no longer use the xth character of any string in words where x <= k. 

In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<unordered_map<char, int>> dict(words[0].size());
        for(int i=0;i<words[0].size();i++){
            for(int j=0;j<words.size();j++){
                dict[i][words[j][i]]++;
            }
        }
        vector<vector<int>> mem(target.size(), vector<int>(words[0].size(), -1));
        return dp(dict, target, 0, 0, mem);
    }
private:
    const int mod = 1e9+7;
    long long dp(vector<unordered_map<char, int>>& dict, string& target, int i1, int i2, vector<vector<int>>& mem){
        if(i1==target.size()) return 0;
        if(i2==dict.size()) return 0;
        if(i1==target.size()-1 && dict[i2].count(target[i1])) return dict[i2][target[i1]]+dp(dict, target, i1, i2+1, mem)%mod;
        if(mem[i1][i2]!=-1) return mem[i1][i2];

        long long res = dp(dict, target, i1, i2+1, mem)%mod;
        if(dict[i2].count(target[i1])){
            res = (res + dict[i2][target[i1]]*dp(dict, target, i1+1, i2+1, mem))%mod;
        }
        return mem[i1][i2] = res;
    }
};

int main(void){
    Solution solution;
    vector<string> words;
    string target;

    words = {"acca","bbbb","caca"};
    target = "aba";
    cout << solution.numWays(words, target) << endl;

    words = {"abba","baab"};
    target = "bab";
    cout << solution.numWays(words, target) << endl;

    words = {"cbabddddbc","addbaacbbd","cccbacdccd","cdcaccacac","dddbacabbd","bdbdadbccb","ddadbacddd","bbccdddadd","dcabaccbbd","ddddcddadc","bdcaaaabdd","adacdcdcdd","cbaaadbdbb","bccbabcbab","accbdccadd","dcccaaddbc","cccccacabd","acacdbcbbc","dbbdbaccca","bdbddbddda","daabadbacb","baccdbaada","ccbabaabcb","dcaabccbbb","bcadddaacc","acddbbdccb","adbddbadab","dbbcdcbcdd","ddbabbadbb","bccbcbbbab","dabbbdbbcb","dacdabadbb","addcbbabab","bcbbccadda","abbcacadac","ccdadcaada","bcacdbccdb"};
    target = "bcbbcccc";
    cout << solution.numWays(words, target) << endl;
    return 0;
}