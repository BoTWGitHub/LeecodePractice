/*
Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. 
You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(n, 2, temp, res);
        if(!res.empty()) res.pop_back();
        return res;
    }
private:
    void backtrack(int& n, int last, vector<int>& temp, vector<vector<int>>& res){
        if(n==1){
            if(!temp.empty()) res.push_back(temp);
            return;
        }

        for(int i=last;i<=n;i++){
            if(n%i==0){
                temp.push_back(i);
                n/=i;
                backtrack(n, i, temp, res);
                n*=i;
                temp.pop_back();
            }
        }
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> res;

    n = 1;
    res = solution.getFactors(n);
    print2DVector(res);

    n = 12;
    res = solution.getFactors(n);
    print2DVector(res);

    n = 37;
    res = solution.getFactors(n);
    print2DVector(res);

    n = 7733671;
    res = solution.getFactors(n);
    print2DVector(res);
    return 0;
}