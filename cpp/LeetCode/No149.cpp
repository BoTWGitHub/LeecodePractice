/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane
, return the maximum number of points that lie on the same straight line.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;
        for(int i=0;i<n-1;i++){
            unordered_map<double, vector<int>> slopes;
            unordered_map<int, vector<int>> verticals;
            for(int j=i+1;j<n;j++){
                double dx = points[i][0]-points[j][0];
                double dy = points[i][1]-points[j][1];
                if(dx==0){
                    verticals[points[i][0]].push_back(j);
                    res = max(res, (int)verticals[points[i][0]].size()+1);
                }
                else{
                    double slope = dy/dx;
                    slopes[slope].push_back(j);
                    res = max(res, (int)slopes[slope].size()+1);
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> points;

    points = {{1,1},{2,2},{3,3}};
    cout << solution.maxPoints(points) << endl;

    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << solution.maxPoints(points) << endl;

    points = {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
    cout << solution.maxPoints(points) << endl;
    return 0;
}