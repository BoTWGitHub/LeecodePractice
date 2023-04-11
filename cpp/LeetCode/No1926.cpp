/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. 
You cannot step into a cell with a wall, and you cannot step outside the maze. 
Your goal is to find the nearest exit from the entrance. 
An exit is defined as an empty cell that is at the border of the maze. 
The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        visited[entrance[0]][entrance[1]] = true;
        int res = 0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                pair<int, int> p = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int dx = p.first+dirs[j];
                    int dy = p.second+dirs[j+1];
                    if(dx<0 || dx>=maze.size() || dy<0 || dy>=maze[0].size() || maze[dx][dy]=='+' || visited[dx][dy]) continue;
                    if(dx==0 || dx==maze.size()-1 || dy==0 || dy==maze[0].size()-1) return res;
                    visited[dx][dy] = true;
                    q.push({dx, dy});
                }
            }
        }
        return -1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    vector<vector<char>> maze;
    vector<int> entrance;

    maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    entrance = {1,2};
    cout << solution.nearestExit(maze, entrance) << endl;

    maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    entrance = {1,0};
    cout << solution.nearestExit(maze, entrance) << endl;

    maze = {{'.','+'}};
    entrance = {0,0};
    cout << solution.nearestExit(maze, entrance) << endl;
    
    maze = {{'.'}};
    entrance = {0,0};
    cout << solution.nearestExit(maze, entrance) << endl;
    return 0;
}