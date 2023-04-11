/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. 
In the beginning, you are standing at index 0, which is equal to '0'. 
You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1') return false;
        int n = s.size();
        vector<int> prefix;
        int temp = 0;
        for(int i=0;i<n;i++){
            temp+=(s[i]=='1');
            prefix.push_back(temp);
        }
        
        int left=0, right=0;
        while(right<n){
            left = left+minJump;
            right = min(n-1, right+maxJump);
            cout << left << "," << right << endl;
            if(prefix[right]-prefix[left-1]==right-left+1) return false;
            if(right==n-1) break;
        }
        cout << "n " << s.size() << endl;
        return true;
    }
};

int main(void){
    Solution solution;
    string s;
    int minJump;
    int maxJump;

    s = "011010";
    minJump = 2;
    maxJump = 3;
    cout << solution.canReach(s, minJump, maxJump) << endl;

    s = "01101110";
    minJump = 2;
    maxJump = 3;
    cout << solution.canReach(s, minJump, maxJump) << endl;
    return 0;
}