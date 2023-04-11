/*
There are n houses in a village. 
We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing)
, or pipe in water from another well to it. 
The costs to lay pipes between houses are given by the array pipes where each pipes[j] = [house1j, house2j, costj] 
represents the cost to connect house1j and house2j together using a pipe. 
Connections are bidirectional, and there could be multiple valid connections between the same two houses with different costs.

Return the minimum total cost to supply water to all houses.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<vector<pair<int, int>>> ajList(n+1);
        for(int i=0;i<wells.size();i++){
            ajList[0].push_back({wells[i], i+1});
            heap.push({wells[i], i+1});
        }
        for(vector<int>& pipe : pipes){
            ajList[pipe[0]].push_back({pipe[2], pipe[1]});
            ajList[pipe[1]].push_back({pipe[2], pipe[0]});
        }
        vector<bool> seen(n+1, false);
        seen[0] = true;
        int count = n;
        int res = 0;
        while(!heap.empty() && count>0){
            auto p = heap.top();
            heap.pop();
            if(!seen[p.second]){
                count--;
                res+=p.first;
                seen[p.second] = true;
                for(pair<int, int> pipe : ajList[p.second]){
                    if(!seen[pipe.second]){
                        heap.push({pipe.first, pipe.second});
                    }
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<int> wells;
    vector<vector<int>> pipes;

    n=3;
    wells = {1,2,2};
    pipes = {{1,2,1},{2,3,1}};
    cout << solution.minCostToSupplyWater(n, wells, pipes) << endl;

    n=2;
    wells = {1,1};
    pipes = {{1,2,1},{1,2,2}};
    cout << solution.minCostToSupplyWater(n, wells, pipes) << endl;
    return 0;
}