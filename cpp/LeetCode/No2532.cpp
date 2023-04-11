/*[
There are k workers who want to move n boxes from an old warehouse to a new one. 
You are given the two integers n and k, and a 2D integer array time of size k x 4 where time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi].

The warehouses are separated by a river and connected by a bridge. 
The old warehouse is on the right bank of the river, and the new warehouse is on the left bank of the river. 
Initially, all k workers are waiting on the left side of the bridge. 
To move the boxes, the ith worker (0-indexed) can :
 - Cross the bridge from the left bank (new warehouse) to the right bank (old warehouse) in leftToRighti minutes.
 - Pick a box from the old warehouse and return to the bridge in pickOldi minutes. Different workers can pick up their boxes simultaneously.
 - Cross the bridge from the right bank (old warehouse) to the left bank (new warehouse) in rightToLefti minutes.
 - Put the box in the new warehouse and return to the bridge in putNewi minutes. Different workers can put their boxes simultaneously.

A worker i is less efficient than a worker j if either condition is met:
 - leftToRighti + rightToLefti > leftToRightj + rightToLeftj
 - leftToRighti + rightToLefti == leftToRightj + rightToLeftj and i > j

The following rules regulate the movement of the workers through the bridge :
 - If a worker x reaches the bridge while another worker y is crossing the bridge, x waits at their side of the bridge.
 - If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge. 
   If more than one worker is waiting on the right side, the one with the lowest efficiency crosses first.
 - If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old warehouse
   , the worker on the left side of the river gets to cross the bridge. 
   If more than one worker is waiting on the left side, the one with the lowest efficiency crosses first.

Return the instance of time at which the last worker reaches the left bank of the river after all n boxes have been put in the new warehouse.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        typedef tuple<int, int, int> task;
        priority_queue<task, vector<task>, greater<task>> left;
        priority_queue<task, vector<task>, greater<task>> right;
        int boxBack = 0, manAssigned = 0, t = 0;
        vector<int> effOrder = getEffOrder(time);
        for(int i=0;i<k;i++) left.push({-1, effOrder[i], i});
        
        while(boxBack<n){
            //cout << "t " << t << " box " << boxBack << " go " << manAssigned << endl;
            if(!right.empty() && (t>=get<0>(right.top()) || manAssigned==n)){
                while(t>get<0>(right.top())){
                    auto [tick, eff, index] = right.top();
                    right.pop();
                    right.push({t, eff, index});
                }
                auto [tick, eff, index] = right.top();
                right.pop();
                //cout << "right " << index << endl;
                t = max(t, tick) + time[index][2];
                boxBack++;
                left.push({t+time[index][3], eff, index});
            }
            else if(manAssigned<n && !left.empty() && t>=get<0>(left.top())){
                while(t>get<0>(left.top())){
                    auto [tick, eff, index] = left.top();
                    left.pop();
                    left.push({t, eff, index});
                }
                auto [tick, eff, index] = left.top();
                left.pop();
                //cout << "left " << index << endl;
                t = max(t, tick) + time[index][0];
                manAssigned++;
                right.push({t+time[index][1], eff, index});
            }
            else{
                if(!right.empty() && left.empty()){
                    t = get<0>(right.top());
                }
                else if(right.empty() && !left.empty()){
                    t = get<0>(left.top());
                }
                else{
                    t = min(get<0>(right.top()), get<0>(left.top()));
                }
            }
        }
        return t;
    }
private:
    vector<int> getEffOrder(vector<vector<int>>& time){
        vector<pair<int, int>> temp;
        for(int i=0;i<time.size();i++){
            temp.push_back({time[i][0]+time[i][2], i});
        }
        sort(temp.begin(), temp.end());
        vector<int> res(time.size());
        int order = time.size()-1;
        for(auto [eff, index] : temp){
            res[index] = order--;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    int k;
    vector<vector<int>> time;

    n = 1;
    k = 3;
    time = {{1,1,2,1},{1,1,3,1},{1,1,4,1}};
    cout << solution.findCrossingTime(n, k, time) << endl;

    n = 3;
    k = 2;
    time = {{1,9,1,8},{10,10,10,10}};
    cout << solution.findCrossingTime(n, k, time) << endl;

    n = 10;
    k = 6;
    time = {{2,10,5,8},{3,5,2,2},{5,8,10,10},{7,8,8,5},{5,6,6,10},{6,10,6,2}};
    cout << solution.findCrossingTime(n, k, time) << endl;

    n = 9;
    k = 6;
    time = {{2,6,9,4},{4,8,7,5},{4,6,7,6},{2,3,3,7},{9,3,6,8},{2,8,8,4}};
    cout << solution.findCrossingTime(n, k, time) << endl;

    n = 10000;
    k = 133;
    time = {{867,913,934,966},{931,909,887,865},{801,937,871,972},{979,879,829,848},{863,823,925,824},{942,966,846,972},{807,873,991,952},{957,991,851,991},{800,843,852,971},{884,861,855,914},{845,947,896,835},{975,853,848,961},{828,926,942,987},{939,881,908,970},{979,819,993,830},{996,875,814,850},{990,987,982,986},{895,933,833,806},{874,933,917,917},{896,927,930,820},{932,810,854,959},{848,921,949,922},{892,918,886,887},{872,953,827,884},{952,869,933,906},{874,934,937,803},{858,940,970,947},{932,824,834,929},{970,918,926,881},{844,821,861,901},{929,887,970,822},{833,848,903,970},{998,886,824,821},{887,992,802,843},{875,983,927,871},{951,811,809,941},{995,943,968,964},{823,894,814,978},{904,825,814,816},{985,934,926,938},{806,868,824,826},{989,990,853,930},{826,849,963,808},{951,873,915,813},{971,961,952,819},{962,879,832,951},{825,871,837,869},{887,950,876,802},{829,976,914,945},{893,943,998,925},{962,878,899,985},{850,852,946,897},{912,919,911,994},{926,911,969,962},{800,972,861,970},{989,850,953,916},{954,809,819,902},{810,906,815,850},{985,877,990,963},{950,832,962,853},{999,974,964,949},{937,980,886,912},{943,850,869,984},{841,913,846,968},{899,877,996,934},{816,973,925,803},{815,851,946,844},{868,852,853,824},{811,836,929,903},{826,837,940,805},{862,942,825,857},{915,923,933,900},{868,812,863,850},{926,996,865,840},{931,950,834,978},{982,985,855,821},{986,876,940,859},{847,911,972,848},{838,938,843,910},{803,947,981,836},{981,801,874,855},{993,949,882,949},{972,910,876,990},{907,951,944,867},{865,860,863,910},{942,897,962,950},{864,987,999,945},{931,877,999,966},{996,862,885,848},{817,956,861,833},{850,973,936,934},{997,924,952,954},{832,930,988,978},{892,934,930,808},{886,889,812,835},{829,835,906,819},{817,965,909,981},{890,890,889,883},{816,901,853,853},{969,999,998,885},{917,853,879,851},{809,807,966,985},{892,827,857,966},{919,864,946,974},{878,808,908,860},{850,937,926,832},{823,865,805,883},{946,878,908,915},{964,932,965,863},{826,993,913,875},{949,826,989,932},{916,878,926,832},{991,816,977,811},{985,879,840,958},{894,943,912,912},{933,845,936,980},{991,944,887,953},{948,871,855,866},{904,839,1000,804},{883,825,889,930},{842,811,801,978},{857,886,803,946},{844,917,833,838},{976,848,911,984},{979,836,957,952},{932,803,956,889},{936,835,933,842},{900,940,978,914},{838,934,934,848},{898,877,844,940},{833,874,879,850},{963,880,925,964},{800,898,952,812}};
    cout << solution.findCrossingTime(n, k, time) << endl;
    return 0;
}