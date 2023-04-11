/*
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. 
However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. 
Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> keys;
        for(int key : rooms[0]) keys.push(key);
        visited[0] = true;
        while(!keys.empty()){
            int key = keys.front();
            keys.pop();
            if(!visited[key]){
                visited[key] = true;
                for(int k : rooms[key]) keys.push(k);
            }
        }
        bool res = true;
        for(bool v : visited) res&=v;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> rooms;

    rooms = {{1},{2},{3},{}};
    cout << solution.canVisitAllRooms(rooms) << endl;

    rooms = {{1,3},{3,0,1},{2},{0}};
    cout << solution.canVisitAllRooms(rooms) << endl;
    return 0;
}