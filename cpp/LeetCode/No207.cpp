/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> dp(numCourses, false);
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        for(vector<int> v : prerequisites){
            graph[v[0]][v[1]] = true;;
        }
        for(int i=0;i<numCourses;i++){
            vector<bool> mem(numCourses, false);
            if(!dp[i] && !backtrack(i, numCourses, dp, graph, mem)){
                return false;
            }
        }
        return true;
    }
private:
    bool backtrack(int node, int max, vector<bool> &dp, vector<vector<bool>> &graph, vector<bool> &mem){
        if(mem[node]) return false;
        mem[node] = true;
        for(int i=0;i<max;i++){
            if(graph[node][i]){
                if(!dp[i] && !backtrack(i, max, dp, graph, mem)){
                    return false;
                }
            }
        }
        dp[node] = true;
        mem[node] = false;
        return true;
    }
};

int main(void){
    Solution solution;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << solution.canFinish(numCourses, prerequisites) << endl;
    return 0;
}