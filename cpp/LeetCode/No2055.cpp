/*
There is a long table with a line of plates and candles arranged on top of it. 
You are given a 0-indexed string s consisting of characters '*' and '|' only
, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] 
denotes the substring s[lefti...righti] (inclusive). 
For each query, you need to find the number of plates between candles that are in the substring. 
A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". 
The number of plates between candles in this substring is 2
, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        unordered_map<int, int> prefixMap;
        vector<int> rightMap(s.size()+1, 0);
        vector<int> leftMap(s.size()+1, 0);
        int left = 0, right = 0;
        while(left<s.size() && s[left]=='*'){
            left++;
        }
        prefixMap[left] = 0;
        for(int i=0;i<=left;i++) leftMap[i] = left;
        int count = 0;
        right = left+1;
        rightMap[left] = left;
        while(left<s.size() && right<s.size()){
            rightMap[left] = left;
            while(right<s.size() && s[right]=='*'){
                count++;
                rightMap[right]=left;
                right++;
            }
            for(int i=left+1;i<=right;i++) leftMap[i] = right;
            prefixMap[right] = count;
            left = right;
            right++;
        }
        rightMap[left] = left;

        vector<int> res;
        for(vector<int> p : queries){
            int left = leftMap[p[0]];
            int right = rightMap[p[1]];
            if(left<right)
                res.push_back(prefixMap[right]-prefixMap[left]);
            else
                res.push_back(0);
        }
        return res;
    }
};

int main(){
    Solution solution;

    //string s = "***|**|*****|**||**|*";
    //vector<vector<int>> queries = {{1,17}, {4,5}, {14,17}, {5,11}, {15,16}};
    string s = "**|**|***|";
    vector<vector<int>> queries = {{2,5}, {5,9}};
    vector<int> res = solution.platesBetweenCandles(s, queries);
    printVector(res);
    return 0;
}
