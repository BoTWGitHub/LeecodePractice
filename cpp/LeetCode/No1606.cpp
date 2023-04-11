/*
You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. 
Each server has infinite computational capacity but cannot handle more than one request at a time. 
The requests are assigned to servers according to a specific algorithm:

 - The ith (0-indexed) request arrives.
 - If all servers are busy, the request is dropped (not handled at all).
 - If the (i % k)th server is available, assign the request to that server.
 - Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). 
   For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request
, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). 
Your goal is to find the busiest server(s). 
A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). 
You may return the IDs in any order.
*/
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> handle(k, 0);
        set<int> idle;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(int i=0;i<k;i++) idle.insert(i);
        for(int i=0;i<n;i++){
            while(!heap.empty() && heap.top().first<=arrival[i]){
                auto [t, s] = heap.top();
                heap.pop();
                idle.insert(s);
            }
            if(!idle.empty()){
                auto it = idle.lower_bound(i%k);
                if(it==idle.end()){
                    it = idle.begin();
                }
                int s = *it;
                heap.push({arrival[i]+load[i], s});
                idle.erase(s);
                handle[s]++;
            }
        }
        
        vector<int> res;
        int temp = *max_element(handle.begin(), handle.end());
        for(int i=0;i<k;i++){
            if(handle[i]==temp) res.push_back(i);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int k;
    vector<int> arrival;
    vector<int> load;
    vector<int> res;

    k = 3;
    arrival = {1,2,3,4,5};
    load = {5,2,3,3,3};
    res = solution.busiestServers(k, arrival, load);
    printVector(res);

    k = 3;
    arrival = {1,2,3,4};
    load = {1,2,1,2};
    res = solution.busiestServers(k, arrival, load);
    printVector(res);

    k = 3;
    arrival = {1,2,3};
    load = {10,11,12};
    res = solution.busiestServers(k, arrival, load);
    printVector(res);

    k = 3;
    arrival = {1,2,3,4,8,9,10};
    load = {5,2,10,3,1,2,2};
    res = solution.busiestServers(k, arrival, load);
    printVector(res);
    return 0;
}