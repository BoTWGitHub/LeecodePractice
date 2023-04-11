/*
A certain bug's home is on the x-axis at position x. Help them get there from position 0.

The bug jumps according to the following rules:

It can jump exactly a positions forward (to the right).
It can jump exactly b positions backward (to the left).
It cannot jump backward twice in a row.
It cannot jump to any forbidden positions.
The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

Given an array of integers forbidden
, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x
, return the minimum number of jumps needed for the bug to reach its home. 
If there is no possible sequence of jumps that lands the bug on position x, return -1.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x==0) return 0;
        unordered_set<int> banned_f(forbidden.begin(), forbidden.end());
        unordered_set<int> banned_b(forbidden.begin(), forbidden.end());
        queue<pair<int, int>> q;
        q.push({0, 0});
        banned_f.insert(0);
        banned_b.insert(0);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                auto [pos, back] = q.front();
                //cout << "pos " << pos << ", back " << back << ", res " << res << endl;
                q.pop();
                int forward = pos+a;
                if(forward==x) return res;
                if(banned_f.count(forward)==0 && ((a<b && forward<=2000+2*b) || (a>=b && forward<=x+b))){
                    banned_f.insert(forward);
                    q.push({forward, 0});
                }
                if(back==0){
                    int backward = pos-b;
                    if(backward==x) return res;
                    if(backward>0 && banned_b.count(backward)==0){
                        banned_b.insert(backward);
                        q.push({backward, 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution solution;
    vector<int> forbidden;
    int a, b, x;

    forbidden = {14,4,18,1,15};
    a = 3;
    b = 15;
    x = 9;
    cout << solution.minimumJumps(forbidden, a, b, x) << endl;

    forbidden = {8,3,16,6,12,20};
    a = 15;
    b = 13;
    x = 11;
    cout << solution.minimumJumps(forbidden, a, b, x) << endl;

    forbidden = {1,6,2,14,5,17,4};
    a = 16;
    b = 9;
    x = 7;
    cout << solution.minimumJumps(forbidden, a, b, x) << endl;

    forbidden = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    a = 29;
    b = 98;
    x = 80;
    cout << solution.minimumJumps(forbidden, a, b, x) << endl;

    forbidden = {1362,873,1879,725,305,794,1135,1358,1717,159,1370,1861,583,1193,1921,778,1263,239,1224,1925,1505,566,5,15};
    a = 560;
    b = 573;
    x = 64;
    cout << solution.minimumJumps(forbidden, a, b, x) << endl;
    return 0;
}