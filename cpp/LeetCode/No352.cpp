/*
Given a data stream input of non-negative integers a1, a2, ..., an
, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. 
The answer should be sorted by starti.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class SummaryRanges {
public:
    void addNum(int value) {
        if(res.empty()){
            res.push_back({value, value});
        }
        else{
            int left = 0, right = res.size()-1;
            while(left<right){
                int mid = (right-left)/2+left;
                if(res[mid][1]+1<value) left = mid+1;
                else right = mid;
            }

            if(left==0 && value<res[0][0]-1){
                res.insert(res.begin(), {value, value});
            }
            else if(left==res.size()-1){
                if(value>=res.back()[0]-1 && value<=res.back()[1]+1){
                    res.back()[0] = min(value, res.back()[0]);
                    res.back()[1] = max(value, res.back()[1]);
                }
                else if(value<res.back()[0]-1){
                    vector<int> temp = res.back();
                    res.back()[0] = value;
                    res.back()[1] = value;
                    res.push_back(temp);
                }
                else{
                    res.push_back({value, value});
                }
            }
            else{
                vector<vector<int>> temp;
                for(int i=0;i<left;i++) temp.push_back(res[i]);
                if(value<res[left][0]-1){
                    temp.push_back({value, value});
                    temp.push_back(res[left]);
                }
                else{
                    temp.push_back(res[left]);
                    temp.back()[0] = min(temp.back()[0], value);
                    temp.back()[1] = max(temp.back()[1], value);
                }
                for(int i=left+1;i<res.size();i++){
                    if(res[i][0]<=temp.back()[1]+1){
                        temp.back()[1] = max(temp.back()[1], res[i][1]);
                    }
                    else{
                        temp.push_back(res[i]);
                    }
                }
                res = temp;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }
private:
    vector<vector<int>> res;
};

int main(void){
    SummaryRanges sr;
    sr.addNum(1);
    print2DVector(sr.getIntervals());
    sr.addNum(3);
    print2DVector(sr.getIntervals());
    sr.addNum(7);
    print2DVector(sr.getIntervals());
    sr.addNum(2);
    print2DVector(sr.getIntervals());
    sr.addNum(6);
    print2DVector(sr.getIntervals());
    
    return 0;
}