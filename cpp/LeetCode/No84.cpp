/*
Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        for(int i=0;i<heights.size();i++){
            while(s.size()>0 && heights[i]<heights[s.top()]){
                int index = s.top();
                s.pop();
                int h = heights[index];
                if(s.size()>0){
                    int area = h*(i-s.top()-1);
                    max_area = max(max_area, area);
                }
                else{
                    int area = h*(i);
                    max_area = max(max_area, area);
                }
                
            }
            s.push(i);
        }

        while(s.size()>0){
            int index = s.top();
            s.pop();
            int h = heights[index];
            
            if(s.size()>0){
                int area = h*(heights.size()-s.top()-1);
                max_area = max(max_area, area);
            }
            else{
                int area = h*(heights.size());
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

int main(){
    Solution solution;
    
    vector<int> heights{5,4,1,2};
    cout << solution.largestRectangleArea(heights) << endl;
    return 0;
}
