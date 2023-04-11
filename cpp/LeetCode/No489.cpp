/*
You are controlling a robot that is located somewhere in a room. 
The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty
, and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). 
The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
Note that the initial direction of the robot will be facing up. 
You can assume all four edges of the grid are all surrounded by a wall.
Custom testing:

The input is only given to initialize the room and the robot's position internally. 
You must solve this problem "blindfolded". 
In other words, you must control the robot using only the four mentioned APIs without knowing the room layout and the initial robot's position.
*/
/*
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Robot {
public:
    Robot(int x, int y, vector<vector<int>> &room, bool debug = false){
        pos_x = x;
        pos_y = y;
        this->room = room;
        this->debug = debug;
    }
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move(){
        int x = pos_x;
        int y = pos_y;
        bool result = false;
        switch(dir){
            case 0: //toward top
                x--;
                if(x>=0 && x<room.size() && (room[x][pos_y]!=0)){
                    pos_x = x;
                    result = true;
                }
                break;

            case 1: //toward left
                y--;
                if(y>=0 && y<room[0].size() && (room[pos_x][y]!=0)){
                    pos_y = y;
                    result = true;
                }
                break;

            case 2: //toward down
                x++;
                if(x>=0 && x<room.size() && (room[x][pos_y]!=0)){
                    pos_x = x;
                    result = true;
                }
                break;

            case 3: //toward right
                y++;
                if(y>=0 && y<room[0].size() && (room[pos_x][y]!=0)){
                    pos_y = y;
                    result = true;
                }
                break;

            default:
                return false;
        }
        if(debug){
            cout << "Move [" << dir << "] ";
            if(result) cout << "success! ";
            else cout << "failed... ";
            printInfo();
        }
        return result;
    }

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft(){
        dir = (dir+1)%4;
        if(debug){
            cout << "Turn left [" << dir << "]" << endl;
        }
    }
    void turnRight(){
        dir = (dir-1+4)%4;
        if(debug){
            cout << "Turn right [" << dir << "]" << endl;
        }
    }

    // Clean the current cell.
    void clean(){
        if(debug){
            cout << "Clean [" << pos_x << "][" << pos_y << "]" << endl;
        }
        room[pos_x][pos_y] = 2; //cleaned
    }

    void printInfo(){
        cout << "x:" << pos_x << " y:" << pos_y << " dir:" << dir << endl; 
    }
    void printRoom(){
        cout << "[" << endl;
        for(vector<int> row : room){
            cout << "   [";
            for(int p : row){
                cout << p << ",";
            }
            cout <<"\b]" << endl;
        }
        cout << "]" << endl;
    }
private:
    int pos_x;
    int pos_y;
    int dir = 0;
    bool debug;
    vector<vector<int>> room;
};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot);
    }
private:
    unordered_set<string> cleaned = unordered_set<string>();
    vector<vector<int>> mov{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void markCleaned(int x, int y){
        string pos = to_string(x) + "," + to_string(y);
        cleaned.insert(pos);
    }
    bool isCleand(int x, int y){
        string pos = to_string(x) + "," + to_string(y);
        if(cleaned.count(pos)>0){
            return true;
        }
        else{
            return false;
        }
    }
    void moveBack(Robot &robot){
        cout << "Go back" << endl;
        cout << "   ";
        robot.turnLeft();
        cout << "   ";
        robot.turnLeft();
        cout << "   ";
        robot.move();
        cout << "   ";
        robot.turnLeft();
        cout << "   ";
        robot.turnLeft();
    }
    void backtrack(Robot &robot, int x = 0, int y = 0, int dir = 0){
        markCleaned(x, y);
        robot.clean();

        for(int i=0;i<4;i++){
            int new_dir = (dir+i)%4;
            int new_x = x+mov[new_dir][0];
            int new_y = y+mov[new_dir][1];
            if(!isCleand(new_x, new_y) && robot.move()){
                backtrack(robot, new_x, new_y, new_dir);
                moveBack(robot);
            }
            switch(new_dir){
                case 0:
                    robot.turnLeft();
                    break;
                case 1:
                    robot.turnLeft();
                    robot.turnLeft();
                    break;
                case 2:
                    robot.turnRight();
                    break;
                case 3:
                    robot.turnRight();
                    robot.turnRight();
                    break;
            }
            
        }
    }
};

int main(){
    Solution solution;

    vector<vector<int>> room{
                                {1,1,1,1,1,0,1,1},
                                {1,1,1,1,1,0,1,1},
                                {1,0,1,1,1,1,1,1},
                                {0,0,0,1,0,0,0,0},
                                {1,1,1,1,1,1,1,1}
                             };
    int row = 1, col = 3;

    Robot robot(row, col, room, true);
    robot.printRoom();

    solution.cleanRoom(robot);

    robot.printRoom();

    return 0;
}