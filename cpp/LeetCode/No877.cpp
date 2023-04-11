/*
Alice and Bob play a game with piles of stones. 
There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. 
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> mem(piles.size(), vector<int>(piles.size(), INT_MAX));
        return dp(piles, 0, piles.size()-1, mem);
    }
private:
    int dp(vector<int> &piles, int left, int right, vector<vector<int>> &mem){
        if(left>right) return 0;
        if(mem[left][right]!=INT_MAX) return mem[left][right];

        int l = piles[left];
        if(piles[left+1]<piles[right]){
            l = l - piles[right] + dp(piles, left+1, right-1, mem);
        }
        else{
            l = l - piles[left+1] + dp(piles, left+2, right, mem);
        }
        int r = piles[right];
        if(piles[right-1]<piles[left]){
            r = r - piles[left] + dp(piles, left+1, right-1, mem);
        }
        else{
            r = r - piles[right-1] + dp(piles, left, right-2, mem);
        }
        mem[left][right] = max(l, r);
        return mem[left][right];
    }
};

int main(void){
    Solution solution;

    vector<int> piles;

    piles = {5,3,4,5};
    cout << solution.stoneGame(piles) << endl;

    piles = {3,7,2,3};
    cout << solution.stoneGame(piles) << endl;

    return 0;
}