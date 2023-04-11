/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list
, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. 
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. 
For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

Constraints:
1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> live;
        vector<pair<int, int>> edges;
        for(int i=0;i<buildings.size();i++){
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        sort(edges.begin(), edges.end());

        vector<vector<int>> res;
        int index = 0;
        while(index<edges.size()){
            int x = edges[index].first;
            while(index<edges.size() && edges[index].first==x){
                live.push({buildings[edges[index].second][2], buildings[edges[index].second][1]});
                index++;
            }
            while(live.size()>0 && x>=live.top().second){
                live.pop();
            }
            int max_height = 0;
            if(live.size()>0){
                max_height = live.top().first;
            }
            if(res.size()==0 || max_height!=res.back()[1]){
                res.push_back({x, max_height});
            }
        }
        return res;
    }
    vector<vector<int>> getSkyline2(vector<vector<int>>& buildings) {
        return divideAndConquer(buildings, 0, buildings.size()-1);
    }
private:
    vector<vector<int>> divideAndConquer(vector<vector<int>>& buildings, int left, int right){
        if(left==right){
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        }

        int mid = (right-left)/2+left;
        vector<vector<int>> leftSkyline = divideAndConquer(buildings, left, mid);
        vector<vector<int>> rightSkyline = divideAndConquer(buildings, mid+1, right);

        int p1 = 0, p2 = 0;
        vector<vector<int>> res;
        int leftH = 0, rightH = 0;
        while(p1<leftSkyline.size() && p2<rightSkyline.size()){
            int leftX = leftSkyline[p1][0], rightX = rightSkyline[p2][0];
            int curX, curY;
            if(leftX<rightX){
                leftH = leftSkyline[p1][1];
                curY = max(leftH, rightH);
                curX = leftX;
                p1++;
            }
            else if(leftX>rightX){
                rightH = rightSkyline[p2][1];
                curY = max(leftH, rightH);
                curX = rightX;
                p2++;
            }
            else{
                leftH = leftSkyline[p1][1];
                rightH = rightSkyline[p2][1];
                curY = max(leftH, rightH);
                curX = leftX;
                p1++;
                p2++;
            }

            if(res.empty() || curY!=res.back()[1]){
                res.push_back({curX, curY});
            }
        }
        while(p1<leftSkyline.size()){
            res.push_back(leftSkyline[p1++]);
        }
        while(p2<rightSkyline.size()){
            res.push_back(rightSkyline[p2++]);
        }
        return res;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> res = solution.getSkyline2(buildings);
    print2DVector(res);

    return 0;
}
