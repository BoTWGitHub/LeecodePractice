'''
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
'''
from typing import List

def printRoom(room):
    print('[')
    for r in room:
        print(f'   {r}')
    print(']')

# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
class Robot:
    def __init__(self, x, y, room):
        self.__x = x
        self.__y = y
        self.__dir = 0
        self.__room = room

    def move(self):
        """
        Returns true if the cell in front is open and robot moves into the cell.
        Returns false if the cell in front is blocked and robot stays in the current cell.
        :rtype bool
        """
        x = self.__x
        y = self.__y
        match(self.__dir):
            case 0:
                x-=1
                if x>=0 and x<len(self.__room) and self.__room[x][y]!=0:
                    self.__x = x
                    return True
            case 1:
                y-=1
                if y>=0 and y<len(self.__room[0]) and self.__room[x][y]!=0:
                    self.__y = y
                    return True
            case 2:
                x+=1
                if x>=0 and x<len(self.__room) and self.__room[x][y]!=0:
                    self.__x = x
                    return True
            case 3:
                y+=1
                if y>=0 and y<len(self.__room[0]) and self.__room[x][y]!=0:
                    self.__y = y
                    return True
        return False

    def turnLeft(self):
        """
        Robot will stay in the same cell after calling turnLeft/turnRight.
        Each turn will be 90 degrees.
        :rtype void
        """
        self.__dir = (self.__dir+1)%4

    def turnRight(self):
        """
        Robot will stay in the same cell after calling turnLeft/turnRight.
        Each turn will be 90 degrees.
        :rtype void
        """
        self.__dir = (self.__dir-1)%4

    def clean(self):
        """
        Clean the current cell.
        :rtype void
        """
        self.__room[self.__x][self.__y] = 2

class Solution:
    def cleanRoom(self, robot: Robot):
        """
        :type robot: Robot
        :rtype: None
        """
        def goBack():
            robot.turnLeft()
            robot.turnLeft()
            robot.move()
            robot.turnRight()
            robot.turnRight()
        
        def backtrack(pos:set = (0, 0), dir:int = 0):
            robot.clean()
            cleaned.add(pos)
            for i in range(4):
                new_dir = (dir+i)%4
                new_pos = (pos[0] + mov[new_dir][0], pos[1] + mov[new_dir][1])
                if new_pos not in cleaned and robot.move():
                    backtrack(new_pos, new_dir)
                    goBack()
                robot.turnLeft()
        
        cleaned = set()
        mov = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        backtrack()


def main():
    solution = Solution()

    room = [[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]]
    row = 1
    col = 3
    printRoom(room)

    robot = Robot(row, col, room)
    solution.cleanRoom(robot)

    printRoom(room)

if __name__=='__main__':
    main()
