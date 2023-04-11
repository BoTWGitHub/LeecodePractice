/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Debug\VectorDebug.h"
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, int> indexMap;
        int index = 0;
        for(vector<string> equation : equations){
            for(string variable : equation){
                if(indexMap.count(variable)==0){
                    indexMap[variable] = index++;
                }
            }
        }
        vector<vector<double>> directedGraph(index, vector<double>(index, 0));
        for(int i=0;i<index;i++) directedGraph[i][i] = 1;
        for(int i=0;i<equations.size();i++){
            int a = indexMap[equations[i][0]], b = indexMap[equations[i][1]];
            directedGraph[a][b] = values[i];
            directedGraph[b][a] = 1/values[i];
        }
        for(vector<string> query : queries){
            if(indexMap.count(query[0])==0 || indexMap.count(query[1])==0){
                res.push_back(-1);
                continue;
            }
            int a = indexMap[query[0]], b = indexMap[query[1]];

            unordered_set<int> seen;
            dfs(directedGraph, a, b, seen);
            if(directedGraph[a][b]==0){
                res.push_back(-1);
            }
            else{
                res.push_back(directedGraph[a][b]);
            }
        }
        return res;
    }
private:
    double dfs(vector<vector<double>> &directedGraph, int v1, int v2, unordered_set<int> &seen){
        if(directedGraph[v1][v2]!=0) return directedGraph[v1][v2];

        seen.insert(v1);
        for(int i=0;i<directedGraph.size();i++){
            if(i!=v1 && seen.count(i)==0 && directedGraph[v1][i]!=0){
                double temp = dfs(directedGraph, i, v2, seen);
                if(temp!=0){
                    directedGraph[v1][v2] = directedGraph[v1][i]*temp;
                    directedGraph[v2][v1] = 1/directedGraph[v1][v2];
                    return directedGraph[v1][v2];
                }
            }
        }
        return 0;
    }
};

int main(void){
    Solution solution;
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    vector<double> res;

    equations = {{"a","b"},{"b","c"}};
    values = {2.0,3.0};
    queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    res = solution.calcEquation(equations, values, queries);
    printVector(res);

    equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    values = {1.5,2.5,5.0};
    queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    res = solution.calcEquation(equations, values, queries);
    printVector(res);

    equations = {{"a","b"}};
    values = {0.5};
    queries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    res = solution.calcEquation(equations, values, queries);
    printVector(res);

    equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    values = {3.0,4.0,5.0,6.0};
    queries = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
    res = solution.calcEquation(equations, values, queries);
    printVector(res);

    return 0;
}