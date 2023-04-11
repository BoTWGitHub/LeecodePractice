/*
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. 
Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. 
If there is no solution return -1.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> mem(colors.size(), vector<int>(3, -1));

        vector<int> index(3, 0);
        for(int i=0;i<colors.size();i++){
            for(int j=index[colors[i]-1];j<=i;j++){
                mem[j][colors[i]-1] = i-j;
            }
            index[colors[i]-1] = i+1;
        }

        for(int i=0;i<3;i++) index[i] = colors.size()-1;
        for(int i=colors.size()-1;i>=0;i--){
            for(int j=index[colors[i]-1];j>=i;j--){
                if(mem[j][colors[i]-1]==-1){
                    mem[j][colors[i]-1] = j-i;
                }
                else{
                    mem[j][colors[i]-1] = min(mem[j][colors[i]-1], j-i);
                }
            }
            index[colors[i]-1] = i-1;
        }

        for(vector<int>& query : queries){
            res.push_back(mem[query[0]][query[1]-1]);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> colors;
    vector<vector<int>> queries;
    vector<int> res;

    colors = {1,1,2,1,3,2,2,3,3};
    queries = {{1,3},{2,2},{6,1}};
    res = solution.shortestDistanceColor(colors, queries);
    printVector(res);

    colors = {1,2};
    queries = {{0,3}};
    res = solution.shortestDistanceColor(colors, queries);
    printVector(res);

    colors = {3,1,1,2,3,3,2,1,2,3,1,1,3,2,3,1,1,1,1,2,2,1,2,2,2,1,1,1,1,2,3,3,3,1,3,2,1,1,2,2,1,3,1,2,1,1,2,2,1,2};
    queries = {{10,2},{0,1},{32,3},{1,1},{41,1},{48,3},{0,3},{46,2},{48,2},{28,1},{47,2},{11,2},{49,3},{3,3},{40,1},{1,2},{42,2},{47,2},{36,3},{23,1},{7,3},{47,2},{13,3},{36,1},{17,2},{46,2},{38,2},{0,1},{38,3},{36,3},{33,1},{11,3},{39,2},{10,2},{44,3},{5,1},{36,3},{44,3},{38,1},{9,1},{9,1},{35,3},{10,1},{9,1},{0,3},{1,1},{0,3},{28,1},{22,3},{15,1}};
    res = solution.shortestDistanceColor(colors, queries);
    printVector(res);

    colors = {3,3,3,1,2,1,3,1,1,2,1,3,2,3,1,2,3,1,2,3,1,2,2,1,3,3,2,3,3,3,3,2,1,3,2,2,2,1,1,2,2,2,2,1,1,2,1,2,2,1,2,3,1,3,3,3,1,2,1,2,3,1,3,3,2,1,3,1,2,1,1,3,3,1,1,3,2,1,1,1,1,3,1,3,3,1,2,2,1,1,3,1,2,2,2,2,3,3,3,1};
    queries = {{3,2},{60,3},{47,2},{30,2},{55,1},{67,2},{44,3},{0,1},{47,2},{42,3},{8,2},{97,3},{43,1},{11,1},{77,3},{94,2},{4,1},{13,1},{2,2},{21,2},{52,3},{43,2},{79,2},{58,3},{6,1},{53,2},{72,3},{5,1},{70,3},{96,2},{99,3},{35,1},{55,3},{10,2},{43,2},{3,3},{52,1},{21,3},{88,3},{35,1},{7,3},{58,2},{92,1},{35,1},{88,2},{27,2},{17,1},{50,1},{23,3},{17,2},{75,1},{66,3},{78,1},{85,3},{31,3},{8,3},{72,3},{34,1},{65,1},{10,1},{85,1},{12,2},{0,3},{84,2},{80,1},{71,1},{9,2},{65,1},{17,3},{5,2},{17,3},{63,3},{28,3},{39,2},{95,3},{95,3},{43,3},{77,3},{39,2},{59,1},{59,2},{46,2},{40,3},{15,2},{17,2},{33,2},{13,2},{8,2},{11,3},{36,1},{57,2},{59,3},{50,1},{55,3},{70,2},{3,3},{45,3},{26,2},{73,1},{71,2}};
    res = solution.shortestDistanceColor(colors, queries);
    printVector(res);
    return 0;
}