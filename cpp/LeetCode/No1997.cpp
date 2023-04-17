/*
There are n rooms you need to visit, labeled from 0 to n - 1. 
Each day is labeled, starting from 0. 
You will go in and visit one room a day.

Initially on day 0, you visit room 0. 
The order you visit the rooms for the coming days is determined by the following rules and a given 0-indexed array nextVisit of length n:

Assuming that on a day, you visit room i,
if you have been in room i an odd number of times (including the current visit)
, on the next day you will visit a room with a lower or equal room number specified by nextVisit[i] where 0 <= nextVisit[i] <= i;

if you have been in room i an even number of times (including the current visit)
, on the next day you will visit room (i + 1) mod n.

Return the label of the first day where you have been in all the rooms. 
It can be shown that such a day exists. 
Since the answer may be very large, return it modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int res = 0;
        int n = nextVisit.size();
        vector<int> count(n, 0);
        int cur = 0;
        count[0] = 1;
        while(cur<n-1){
            cout << cur << ",";
            if(count[cur]%2==1){
                cur = nextVisit[cur];
            }
            else{
                cur = (cur+1)%n;
            }
            count[cur]++;
            res = (res+1)%mod;
        }
        cout << endl;
        return res;
    }
private:
    const int mod = 1e9+7;
};

int main(void){
    Solution solution;
    vector<int> nextVisit;

    nextVisit = {0,0};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;

    nextVisit = {0,0,2};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;

    nextVisit = {0,1,2,0};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;

    nextVisit = {0,0,1,0};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;

    nextVisit = {0,0,2,1,0};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;

    nextVisit = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << solution.firstDayBeenInAllRooms(nextVisit) << endl;
    return 0;
}