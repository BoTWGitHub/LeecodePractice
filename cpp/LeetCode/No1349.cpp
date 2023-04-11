/*
Given a m * n matrix seats  that represent seats distributions in a classroom. 
If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right
, but he cannot see the answers of the student sitting directly in front or behind him. 
Return the maximum number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        row = seats.size();
        col = seats[0].size();
        vector<vector<int>> mem(row, vector<int>(col, -1));
        return dp(seats, 0, 0, 0, 0, mem);
    }
private:
    int row;
    int col;
    int dp(vector<vector<char>>& seats, int x, int y, int thisCol, int lastRow, vector<vector<int>> &mem){
        if(x==row) return 0;
        if(y>=col){
            return dp(seats, x+1, 0, 0, thisCol, mem);
        }
        if(mem[x][y]!=-1) return mem[x][y];

        int left = lastRow<<1, right = lastRow>>1;
        int temp = thisCol|(1<<(col-1-y));
        int res = 0;
        if(seats[x][y]=='.' && (temp&left)==0 && (temp&right)==0){
            res = max(1+dp(seats, x, y+2, temp, lastRow, mem), dp(seats, x, y+1, thisCol, lastRow, mem));
        }
        else{
            res = dp(seats, x, y+1, thisCol, lastRow, mem);
        }
        
        return mem[x][y] = res;
    }
};

int main(void){
    Solution solution;
    vector<vector<char>> seats;

    /*seats = {{'#','.','#','#','.','#'},
             {'.','#','#','#','#','.'},
             {'#','.','#','#','.','#'}};
    cout << solution.maxStudents(seats) << endl;

    seats = {{'.','#'},
             {'#','#'},
             {'#','.'},
             {'#','#'},
             {'.','#'}};
    cout << solution.maxStudents(seats) << endl;

    seats = {{'#','.','.','.','#'},
             {'.','#','.','#','.'},
             {'.','.','#','.','.'},
             {'.','#','.','#','.'},
             {'#','.','.','.','#'}};
    cout << solution.maxStudents(seats) << endl;*/

    seats = {{'.','#','#','.'}
            ,{'.','.','.','#'}
            ,{'.','.','.','.'}
            ,{'#','.','#','#'}};
    cout << solution.maxStudents(seats) << endl;
    return 0;
}