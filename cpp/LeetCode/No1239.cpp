/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        string temp = "";
        for(int i=0;i<arr.size();i++){
            backtrack(arr, i, temp, res);
        }
        
        return res;
    }
private:
    void backtrack(vector<string> &arr, int step, string &temp, int &res){
        if(step==arr.size()){
            res = max(res, int(temp.size()));
            return;
        }
        string s = temp;
        for(int i=step;i<arr.size();i++){
            s+=arr[i];
            unordered_set<char> s2(s.begin(), s.end());
            if(s.size()==s2.size()){
                backtrack(arr, i+1, s, res);
            }
            s = temp;
        }
        res = max(res, int(s.size()));
    }
};

int main(void){
    Solution solution;

    vector<string> arr;

    arr = {"un","iq","ue"};
    cout << solution.maxLength(arr) << endl;

    arr = {"cha","r","act","ers"};
    cout << solution.maxLength(arr) << endl;

    arr = {"abcdefghijklmnopqrstuvwxyz"};
    cout << solution.maxLength(arr) << endl;

    arr = {"aa", "bb"};
    cout << solution.maxLength(arr) << endl;

    return 0;
}