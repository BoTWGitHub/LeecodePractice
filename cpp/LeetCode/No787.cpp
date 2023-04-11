/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.
*/
#include <iostream>
#include <climits>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

//bellman ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> ajList(n);
        for(vector<int> flight : flights) ajList[flight[0]].push_back({flight[1], flight[2]});

        vector<int> p(n, INT_MAX);
        p[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> c = p;
            for(int j=0;j<n;j++){
                if(p[j]==INT_MAX) continue;
                for(pair<int, int>& f : ajList[j]){
                    c[f.first] = min(c[f.first], p[j]+f.second);
                }
            }
            p = c;
        }
        if(p[dst]==INT_MAX) return -1;
        return p[dst];
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> flights;
    int src;
    int dst;
    int k;

    n = 4;
    flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    src = 0;
    dst = 3;
    k = 1;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 3;
    flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 1;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 3;
    flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 0;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 11;
    flights = {{0,3,3},{3,4,3},{4,1,3},{0,5,1},{5,1,100},{0,6,2},{6,1,100},{0,7,1},{7,8,1},{8,9,1},{9,1,1},{1,10,1},{10,2,1},{1,2,100}};
    src = 0;
    dst = 2;
    k = 4;
    cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}