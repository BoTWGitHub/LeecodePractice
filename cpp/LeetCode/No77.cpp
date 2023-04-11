/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;

        backtrack(1, n, k, temp, res);
        return res;
    }
private:
    void backtrack(int start, int end, int size, vector<int> &temp, vector<vector<int>> &res){
        if(temp.size() == size){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            backtrack(i+1, end, size, temp, res);
            temp.pop_back();
        }
    }
};

int main(){
    Solution solution;
    int n = 4;
    int k = 2;
    vector<vector<int>> res = solution.combine(n, k);

    cout << "[" << endl;
    for(vector<int> row : res){
        cout << "   [";
        for(int num : row){
            cout << num << ",";
        }
        cout << "\b]" << endl;
    }
    cout << "]" << endl;
    return 0;
}
