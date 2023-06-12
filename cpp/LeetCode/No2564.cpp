/*
You are given a binary string s, and a 2D integer array queries where queries[i] = [firsti, secondi].

For the ith query, find the shortest substring of s whose decimal value, val
, yields secondi when bitwise XORed with firsti. In other words, val ^ firsti == secondi.

The answer to the ith query is the endpoints (0-indexed) of the substring [lefti, righti] or [-1, -1] if no such substring exists. 
If there are multiple answers, choose the one with the minimum lefti.

Return an array ans where ans[i] = [lefti, righti] is the answer to the ith query.

A substring is a contiguous non-empty sequence of characters within a string.
*/
#include <iostream>
#include <unordered_map>
#include "Debug\VectorDebug.h"

class Solution {
public:
    std::vector<std::vector<int>> substringXorQueries(std::string s, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, std::vector<int>> mem;
        for(std::vector<int>& query : queries){
            int x = query[0]^query[1];
            if(mem.count(x)==0){
                std::string target = intToString(query[0]^query[1]);
                std::size_t found = s.find(target);
                if(found!=std::string::npos){
                    int index = (int)found;
                    mem[x] = {index, index+(int)target.size()-1};
                }
                else{
                    mem[x] = {-1,-1};
                }
            }
            res.push_back(mem[x]);
        }
        return res;
    }
private:
    std::string intToString(int num){
        if(num==0) return "0";
        std::string res = "";
        while(num){
            if(num%2==1){
                res.insert(res.begin(), '1');
            }
            else{
                res.insert(res.begin(), '0');
            }
            num/=2;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::string s;
    std::vector<std::vector<int>> queries;

    s = "101101";
    queries = {{0,5},{1,2}};
    print2DVector(solution.substringXorQueries(s, queries));

    s = "0101";
    queries = {{12,8}};
    print2DVector(solution.substringXorQueries(s, queries));

    s = "1";
    queries = {{4,5}};
    print2DVector(solution.substringXorQueries(s, queries));
    return 0;
}