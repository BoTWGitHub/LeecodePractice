/*
You are given two jugs with capacities jug1Capacity and jug2Capacity liters. 
There is an infinite amount of water supply available. 
Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable
, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

 - Fill any of the jugs with water.
 - Empty any of the jugs.
 - Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity==targetCapacity
        || jug1Capacity==targetCapacity 
        || jug2Capacity==targetCapacity) return true;
        unordered_map<int, unordered_set<int>> seen;
        seen[0].insert(0);
        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [j1, j2] = q.front();
            if(j1==targetCapacity || j2==targetCapacity || j1+j2==targetCapacity) return true;
            q.pop();
            if(seen[0].count(j2)==0){ //empty jug1
                seen[0].insert(j2);
                q.push({0, j2});
            }
            if(seen[j1].count(0)==0){ //empty jug2
                seen[j1].insert(0);
                q.push({j1, 0});
            }
            if(seen[jug1Capacity].count(j2)==0){ //fulfill jug1
                seen[jug1Capacity].insert(j2);
                q.push({jug1Capacity, j2});
            }
            if(seen[j1].count(jug2Capacity)==0){ //fulfill jug2
                seen[j1].insert(jug2Capacity);
                q.push({j1, jug2Capacity});
            }

            if(jug1Capacity-j1>0){ //pour j2 to j1
                int space = jug1Capacity-j1;
                if(space>=j2 && seen[j1+j2].count(0)==0){
                    seen[j1+j2].insert(0);
                    q.push({j1+j2, 0});
                }
                else if(space<j2 && seen[jug1Capacity].count(j2-space)==0){
                    seen[jug1Capacity].insert(j2-space);
                    q.push({jug1Capacity, j2-space});
                }
            }

            if(jug2Capacity-j2>0){ //pour j1 to j2
                int space = jug2Capacity-j2;
                if(space>=j1 && seen[0].count(j2+j1)==0){
                    seen[0].insert(j2+j1);
                    q.push({0, j2+j1});
                }
                else if(space<j1 && seen[j1-space].count(jug2Capacity)==0){
                    seen[j1-space].insert(jug2Capacity);
                    q.push({j1-space, jug2Capacity});
                }
            }
        }
        return false;
    }
};

int main(void){
    Solution solution;
    int jug1Capacity, jug2Capacity, targetCapacity;

    jug1Capacity = 3;
    jug2Capacity = 5;
    targetCapacity = 4;
    cout << solution.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity) << endl;

    jug1Capacity = 2;
    jug2Capacity = 6;
    targetCapacity = 5;
    cout << solution.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity) << endl;

    jug1Capacity = 1;
    jug2Capacity = 2;
    targetCapacity = 3;
    cout << solution.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity) << endl;

    jug1Capacity = 104597;
    jug2Capacity = 104623;
    targetCapacity = 123;
    cout << solution.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity) << endl;
    return 0;
}