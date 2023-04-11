#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution{
public:
    vector<int> ShortestPath(vector<vector<int>> distances, int n, int src){
        vector<vector<pair<int, int>>> ajList(n);
        for(vector<int> dis : distances) ajList[dis[0]].push_back({dis[1], dis[2]});
        
        queue<int> q;
        vector<int> res(n, INT_MAX);
        vector<bool> inQueue(n, false);
        q.push(src);
        res[src] = 0;
        inQueue[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            inQueue[node] = false;
            for(pair<int, int> dis : ajList[node]){
                if(!inQueue[dis.first] && res[node]+dis.second<res[dis.first]){
                    res[dis.first] = res[node]+dis.second;
                    q.push(dis.first);
                    inQueue[dis.first] = true;
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> distances;
    int n;
    int src;
    vector<int> res;

    distances = {{0,1,100},{0,3,200},{0,2,500},{3,1,-150},{1,2,100},{2,3,100}};
    n = 4;
    src = 0;
    res = solution.ShortestPath(distances, n, src);
    for(int num : res) cout << num << ",";
    cout << endl;
    return 0;
}