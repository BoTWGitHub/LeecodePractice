/*
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. 
 For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  
Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) : start(_start), end(_end) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        auto cmp = [](const Interval& i1, const Interval& i2){
            return i1.start>i2.start;
        };
        priority_queue<Interval, vector<Interval>, decltype(cmp)> heap(cmp);
        for(vector<Interval>& s : schedule){
            for(Interval& i : s){
                heap.push(i);
            }
        }
        vector<Interval> res;
        Interval cur = heap.top();
        heap.pop();
        while(!heap.empty()){
            Interval next = heap.top();
            heap.pop();
            if(next.start>cur.end){
                res.push_back(Interval(cur.end, next.start));
                cur = next;
            }
            else{
                cur.end = max(cur.end, next.end);
            }
        }
        return res;
    }
};

int main(void){

    return 0;
}