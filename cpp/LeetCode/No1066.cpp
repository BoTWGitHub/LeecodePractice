/*
On a campus represented as a 2D grid, there are n workers and m bikes, with n <= m. 
Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> mem(workers.size(), vector<int>((1<<bikes.size()), -1));
        return dp(workers, bikes, 0, 0, mem);
    }
private:
    int dp(vector<vector<int>>& workers, vector<vector<int>>& bikes, int index, int assigned, vector<vector<int>>& mem){
        if(index==workers.size()) return 0;
        if(mem[index][assigned]!=-1) return mem[index][assigned];
        
        int res = INT_MAX;
        for(int i=0;i<bikes.size();i++){
            if(((1<<i)&assigned)==0){
                int temp = dp(workers, bikes, index+1, assigned|(1<<i), mem);
                if(temp!=INT_MAX) temp+=(abs(workers[index][0]-bikes[i][0])+abs(workers[index][1]-bikes[i][1]));
                res = min(res, temp);
            }
        }
        return mem[index][assigned] = res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> workers;
    vector<vector<int>> bikes;

    workers = {{0,0},{2,1}};
    bikes = {{1,2},{3,3}};
    cout << solution.assignBikes(workers, bikes) << endl;

    workers = {{0,0},{1,1},{2,0}};
    bikes = {{1,0},{2,2},{2,1}};
    cout << solution.assignBikes(workers, bikes) << endl;

    workers = {{0,0},{1,0},{2,0},{3,0},{4,0}};
    bikes = {{0,999},{1,999},{2,999},{3,999},{4,999}};
    cout << solution.assignBikes(workers, bikes) << endl;
    return 0;
}