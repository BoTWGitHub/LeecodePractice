/*
Koko loves to eat bananas. 
There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h==piles.size()) return *max_element(piles.begin(), piles.end());
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left<right){
            int mid = (right-left)/2+left;
            int t = 0;
            for(int p : piles) t+=(p/mid+(p%mid>0));
            //cout << left << "," << mid << "," << right << " : " << t << endl;
            if(t<=h) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

int main(void){
    Solution solution;
    vector<int> piles;
    int h;

    piles = {3,6,7,11};
    h = 8;
    cout << solution.minEatingSpeed(piles, h) << endl;

    piles = {30,11,23,4,20};
    h = 5;
    cout << solution.minEatingSpeed(piles, h) << endl;

    piles = {30,11,23,4,20};
    h = 6;
    cout << solution.minEatingSpeed(piles, h) << endl;

    piles = {1,1,1,999999999};
    h = 10;
    cout << solution.minEatingSpeed(piles, h) << endl;
    return 0;
}