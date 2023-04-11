/*
You are given a string s and an integer k. 
You can choose one of the first k letters of s and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
*/
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        queue<string> q;
        q.push(s);
        string res = s;
        unordered_set<string> seen;
        seen.insert(s);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string temp = q.front();
                q.pop();
                res = min(res, temp);
                for(int i=1;i<=k;i++){
                    string after = move(temp, i);
                    if(seen.count(after)==0){
                        seen.insert(after);
                        q.push(after);
                    }
                }
            }
        }
        return res;
    }
private:
    string move(string org, int k){
        if(k>=org.size()) return org;
        char temp = org[k-1];
        for(int i=k;i<org.size();i++){
            org[i-1] = org[i];
        }
        org.back() = temp;
        return org;
    }
};

int main(void){
    Solution solution;
    string s;
    int k;

    s="cba";
    k=1;
    cout << solution.orderlyQueue(s, k) << endl;

    s="baaca";
    k=3;
    cout << solution.orderlyQueue(s, k) << endl;

    s="kuh";
    k=1;
    cout << solution.orderlyQueue(s, k) << endl;

    s="xyokshvwx";
    k=9;
    cout << solution.orderlyQueue(s, k) << endl;

    s="mqvgtdfuiv";
    k=10;
    cout << solution.orderlyQueue(s, k) << endl;
    return 0;
}