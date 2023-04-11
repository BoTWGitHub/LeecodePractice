/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.
*/
#include <iostream>
#include <stack>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> sk;
        for(int asteroid : asteroids){
            bool push = true;
            while(!sk.empty() && sk.top()>0 && asteroid<0){
                if(abs(asteroid)>sk.top()) sk.pop();
                else if(abs(asteroid)==sk.top()){
                    sk.pop();
                    push = false;
                    break;
                }
                else{
                    push = false;
                    break;
                }
            }
            if(push) sk.push(asteroid);
        }
        vector<int> res;
        while(!sk.empty()){
            res.insert(res.begin(), sk.top());
            sk.pop();
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> asteroids;
    vector<int> res;

    asteroids = {5,10,-5};
    res = solution.asteroidCollision(asteroids);
    printVector(res);

    asteroids = {8,-8};
    res = solution.asteroidCollision(asteroids);
    printVector(res);

    asteroids = {10,2,-5};
    res = solution.asteroidCollision(asteroids);
    printVector(res);

    asteroids = {-2,-1,1,2};
    res = solution.asteroidCollision(asteroids);
    printVector(res);
    return 0;
}