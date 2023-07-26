/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
When the ball stops, it could choose the next direction. 
There is also a hole in this maze. 
The ball will drop into the hole if it rolls onto the hole.

Given the m x n maze, the ball's position ball and the hole's position hole, where ball = [ballrow, ballcol] and hole = [holerow, holecol]
, return a string instructions of all the instructions that the ball should follow to drop in the hole with the shortest distance possible. 
If there are multiple valid instructions, return the lexicographically minimum one. If the ball can't drop in the hole, return "impossible".

If there is a way for the ball to drop in the hole, the answer instructions should contain the characters 'u' (i.e., up), 'd' (i.e., down), 'l' (i.e., left), and 'r' (i.e., right).

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int row = maze.size();
        int col = maze[0].size();
        string res = "";
        int shortestLen = INT_MAX;
        queue<pair<vector<int>, string>> q;
        vector<vector<int>> visited(row, vector<int>(col, INT_MAX));
        visited[ball[0]][ball[1]] = 0;
        q.push({{ball[0], ball[1], 0}, ""});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [node, path] = q.front();
                //cout << node[0] << "," << node[1] << " " << path << "," << node[2] << endl;
                q.pop();
                for(int d=0;d<4;d++){
                    int dx = node[0]+dirs[d];
                    int dy = node[1]+dirs[d+1];
                    if(dx<0 || dx>=row || dy<0 || dy>=col || maze[dx][dy]==1) continue;
                    bool reach = false;
                    int count = 0;
                    string temp = path;
                    temp.push_back(pathChar[d]);
                    while(dx>=0 && dx<row && dy>=0 && dy<col && maze[dx][dy]==0){
                        count++;
                        if(dx==hole[0] && dy==hole[1]){
                            //cout << "reached " << temp << "," << count+node[2] << endl;
                            if(res.empty() || count+node[2]<shortestLen){
                                shortestLen = count+node[2];
                                res = temp;
                            }
                            else if(count+node[2]==shortestLen){
                                res = min(res, temp);
                            }
                            reach = true;
                            break;
                        }
                        dx+=dirs[d];
                        dy+=dirs[d+1];
                    }
                    if(reach) continue;
                    dx-=dirs[d];
                    dy-=dirs[d+1];
                    if(count+node[2]<=visited[dx][dy]){
                        visited[dx][dy] = count+node[2];
                        q.push({{dx, dy, count+node[2]}, temp});
                    }
                }
            }
        }
        return res.empty()?"impossible":res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    const vector<char> pathChar = {'d','l','u','r'};
};

int main(void){
    Solution solution;
    vector<vector<int>> maze;
    vector<int> ball;
    vector<int> hole;

    maze = {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
    ball = {4,3};
    hole = {0,1};
    cout << solution.findShortestWay(maze, ball, hole) << endl;

    maze = {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
    ball = {4,3};
    hole = {3,0};
    cout << solution.findShortestWay(maze, ball, hole) << endl;

    maze = {{0,0,0,0,0,0,0},{0,0,1,0,0,1,0},{0,0,0,0,1,0,0},{0,0,0,0,0,0,1}};
    ball = {0,4};
    hole = {3,5};
    cout << solution.findShortestWay(maze, ball, hole) << endl;

    maze = {{0,0,0,0,0,0,0},{0,0,1,0,0,1,0},{0,0,0,0,1,0,0},{0,0,0,0,0,0,1}};
    ball = {0,4};
    hole = {2,0};
    cout << solution.findShortestWay(maze, ball, hole) << endl;

    maze = {{0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0},{0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},{0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0},{0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0},{0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0},{0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1},{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0},{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0},{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0},{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1}};
    ball = {29,18};
    hole = {14,22};
    cout << solution.findShortestWay(maze, ball, hole) << endl;
    
    maze = {{0,1,0,0,1,0,0,1,0,0},{0,0,1,0,0,1,0,0,1,0},{0,0,0,0,0,0,1,0,0,1},{0,0,0,0,0,0,1,0,0,1},{0,1,0,0,1,0,0,1,0,0},{0,0,1,0,0,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0},{1,0,0,1,0,0,0,0,0,1},{0,1,0,0,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,0}};
    ball = {2,4};
    hole = {7,6};
    cout << solution.findShortestWay(maze, ball, hole) << endl;
    return 0;
}