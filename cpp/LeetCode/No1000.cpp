/*
There are n piles of stones arranged in a row. 
The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, 
and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        return -1;
    }
private:
};

int main(void){
    Solution solution;
    vector<int> stones;
    int k;

    /*stones = {3,2,4,1};
    k = 2;
    cout << solution.mergeStones(stones, k) << endl;

    stones = {3,2,4,1};
    k = 3;
    cout << solution.mergeStones(stones, k) << endl;

    stones = {3,5,1,2,6};
    k = 3;
    cout << solution.mergeStones(stones, k) << endl;*/

    stones = {6,4,4,6};
    k = 2;
    cout << solution.mergeStones(stones, k) << endl;

    /*stones = {69,39,79,78,16,6,36,97,79,27,14,31,4};
    k = 2;
    cout << solution.mergeStones(stones, k) << endl;

    stones = {95,54,31,48,44,96,99,20,51,54,18,85,25,84,91,48,40,72,22};
    k = 2;
    cout << solution.mergeStones(stones, k) << endl;*/

    return 0;
}