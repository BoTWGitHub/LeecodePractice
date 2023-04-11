/*
Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. 
If it is not possible to rearrange the string, return an empty string "".
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k<=1) return s;
        int n = s.size();
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> heap;
        for(auto [c, count] : freq) heap.push({count, c});
        queue<pair<int, char>> q;
        string res;
        while(!heap.empty()){
            auto [count, c] = heap.top();
            heap.pop();
            res.push_back(c);
            count--;
            q.push({count, c});
            if(q.size()==k){
                auto [c1, c2] = q.front();
                q.pop();
                if(c1>0) heap.push({c1, c2});
            }
        }
        if(res.size()<s.size()) return "";
        return res;
    }
};

int main(void){
    Solution solution;
    string s;
    int k;

    s = "aabbcc";
    k = 3;
    cout << solution.rearrangeString(s, k) << endl;

    s = "aaabc";
    k = 3;
    cout << solution.rearrangeString(s, k) << endl;

    s = "aaadbbcc";
    k = 2;
    cout << solution.rearrangeString(s, k) << endl;

    s = "aabbcc";
    k = 2;
    cout << solution.rearrangeString(s, k) << endl;

    s = "aaabc";
    k = 2;
    cout << solution.rearrangeString(s, k) << endl;

    s = "abcdabcdabdeac";
    k = 4;
    cout << solution.rearrangeString(s, k) << endl;

    s = "bbabcaccaaabababbaaaaccbbcbacbacacccbbcaabcbcacaaccbabbbbbcacccaccbabaccbacabcabcacb";
    k = 2;
    cout << solution.rearrangeString(s, k) << endl;
    return 0;
}