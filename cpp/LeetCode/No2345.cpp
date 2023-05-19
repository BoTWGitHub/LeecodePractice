/*
You are given a 0-indexed 2D integer array peaks where peaks[i] = [xi, yi] states that mountain i has a peak at coordinates (xi, yi). 
A mountain can be described as a right-angled isosceles triangle, with its base along the x-axis and a right angle at its peak. 
More formally, the gradients of ascending and descending the mountain are 1 and -1 respectively.

A mountain is considered visible if its peak does not lie within another mountain (including the border of other mountains).

Return the number of visible mountains.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "Debug\VectorDebug.h"

class Solution {
public:
    int visibleMountains(std::vector<std::vector<int>>& peaks) {
        int n = peaks.size();
        std::sort(peaks.begin(), peaks.end());
        std::stack<std::vector<int>> sk;
        std::vector<bool> visible(n, true);
        for(int i=0;i<n;i++){
            if(sk.empty() || 
            (peaks[i][1]+peaks[i][0]>sk.top()[1]+sk.top()[0] 
            && peaks[i][1]-peaks[i][0]<sk.top()[1]-sk.top()[0])){
                sk.push({peaks[i][0], peaks[i][1], i});
            }
            else if(peaks[i][0]==sk.top()[0] && peaks[i][1]==sk.top()[1]){
                visible[i] = false;
                visible[sk.top()[2]] = false;
            }
            else if(peaks[i][1]-peaks[i][0]>=sk.top()[1]-sk.top()[0]){
                while(!sk.empty() && peaks[i][1]-peaks[i][0]>=sk.top()[1]-sk.top()[0]){
                    visible[sk.top()[2]] = false;
                    sk.pop();
                }
                sk.push({peaks[i][0], peaks[i][1], i});
            }
            else{
                visible[i] = false;
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) res+=visible[i];
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<std::vector<int>> peaks;

    peaks = {{2,2},{6,3},{5,4}};
    std::cout << solution.visibleMountains(peaks) << std::endl;

    peaks = {{1,3},{1,3}};
    std::cout << solution.visibleMountains(peaks) << std::endl;

    peaks = {{38,26},{3,32},{2,1}};
    std::cout << solution.visibleMountains(peaks) << std::endl;

    peaks = {{3,19},{39,7},{15,39},{23,13},{8,28},{2,26},{38,15},{38,7},{16,17}};
    std::cout << solution.visibleMountains(peaks) << std::endl;

    peaks = {{2,2},{2,2},{3,1}};
    std::cout << solution.visibleMountains(peaks) << std::endl;

    peaks = {{12,10},{37,25},{8,12},{8,36},{39,4},{22,3},{36,19},{3,17},{10,19},{19,38},{6,36},{27,23},{4,29},{36,27},{21,28},{9,11},{24,1},{16,17},{16,9},{22,23},{37,31},{34,17},{19,2},{33,3},{12,14},{23,7},{20,36},{7,36},{16,7},{24,38}};
    std::cout << solution.visibleMountains(peaks) << std::endl;
    return 0;
}