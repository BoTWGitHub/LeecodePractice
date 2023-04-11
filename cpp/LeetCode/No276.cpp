/*
You are painting a fence of n posts with k different colors. 
You must paint the posts following these rules:

Every post must be painted exactly one color.
There cannot be three or more consecutive posts with the same color.
Given the two integers n and k, return the number of ways you can paint the fence.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> mem(n, vector<int>(2, -1));
        return dp(n, k, 0, -1, false, mem);
    }
private:
    int dp(int n, int k, int index, int last, bool continueTwo, vector<vector<int>> &mem){
        if(mem[index][continueTwo]!=-1) return mem[index][continueTwo];

        if(index == n-1){
            if(continueTwo){
                mem[index][continueTwo] = k-1;
            }
            else{
                mem[index][continueTwo] = k;
            }
            return mem[index][continueTwo];
        }

        int res = 0;
        for(int i=0;i<k;i++){
            if(i==last){
                if(!continueTwo){
                    res+=dp(n, k, index+1, i, true, mem);
                }
            }
            else{
                res+=dp(n, k, index+1, i, false, mem);
            }
        }
        mem[index][continueTwo] = res;
        return res;
    }
};

int main(void){
    Solution solution;

    int n, k;

    n = 3;
    k = 2;
    cout << solution.numWays(n, k) << endl;

    n = 1;
    k = 1;
    cout << solution.numWays(n, k) << endl;

    n = 7;
    k = 2;
    cout << solution.numWays(n, k) << endl;

    return 0;
}