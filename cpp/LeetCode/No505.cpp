/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
The ball can go through the empty spaces by rolling up, down, left or right, 
but it won't stop rolling until hitting a wall. 
When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, 
where start = [startrow, startcol] and destination = [destinationrow, destinationcol], 
return the shortest distance for the ball to stop at the destination. 
If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> mem(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        mem[start[0]][start[1]] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        start.insert(start.begin(), 0);
        q.push(start);
        while(!q.empty()){
            vector<int> pos = q.top();
            q.pop();
            for(int i=0;i<4;i++){
                int x = pos[1];
                int y = pos[2];
                int count = 0;
                while(x+dirs[i]>=0 && x+dirs[i]<maze.size() 
                   && y+dirs[i+1]>=0 && y+dirs[i+1]<maze[0].size() 
                   && maze[x+dirs[i]][y+dirs[i+1]]!=1){
                    x+=dirs[i];
                    y+=dirs[i+1];
                    count++;
                }
                if(count!=0 && count+pos[0]<mem[x][y]){
                    mem[x][y] = count+pos[0];
                    q.push({mem[x][y], x, y,});
                }
            }
        }
        if(mem[destination[0]][destination[1]]==INT_MAX) return -1;
        return mem[destination[0]][destination[1]];
    }
private:
    const vector<int> dirs = {0,1,0,-1,0};
};

int main(void){
    Solution solution;
    vector<vector<int>> maze;
    vector<int> start;
    vector<int> destination;

    maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    start = {0,4};
    destination = {4,4};
    cout << solution.shortestDistance(maze, start, destination) << endl;

    maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    start = {0,4};
    destination = {3,2};
    cout << solution.shortestDistance(maze, start, destination) << endl;

    maze = {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
    start = {4,3};
    destination = {0,1};
    cout << solution.shortestDistance(maze, start, destination) << endl;

    return 0;
}