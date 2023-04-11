/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. 
You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. 
Return -1 if it is not possible.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        
        int n = routes.size();
        vector<bool> seen(n, false);
        unordered_set<int> visited;
        unordered_map<int, vector<int>> busAtStop;
        for(int i=0;i<n;i++){
            for(int stop : routes[i]){
                busAtStop[stop].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        for(int bus : busAtStop[source]){
            seen[bus] = true;
            for(int stop : routes[bus]){
                if(visited.count(stop)==0){
                    visited.insert(stop);
                    q.push({bus, stop});
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                auto [bus, stop] = q.front();
                q.pop();
                if(stop==target) return res;
                for(int newBus : busAtStop[stop]){
                    if(!seen[newBus]){
                        seen[newBus] = true;
                        for(int newStop : routes[newBus]){
                            if(visited.count(newStop)==0){
                                visited.insert(newStop);
                                q.push({newBus, newStop});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> routes;
    int source;
    int target;

    routes = {{1,2,7},{3,6,7}};
    source = 1;
    target = 6;
    cout << solution.numBusesToDestination(routes, source, target) << endl;

    routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    source = 15;
    target = 12;
    cout << solution.numBusesToDestination(routes, source, target) << endl;
    return 0;
}