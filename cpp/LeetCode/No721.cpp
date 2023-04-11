/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name
, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. 
Note that even if two accounts have the same name, they may belong to different people as people could have the same name. 
A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: 
the first element of each account is the name, and the rest of the elements are emails in sorted order. 
The accounts themselves can be returned in any order.
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class UnionFind{
public:
    UnionFind(int n){
        root = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0;i<n;i++) root[i] = i;
    }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]) root[rx] = ry;
            else if(rank[ry]<rank[rx]) root[ry] = rx;
            else{
                root[rx] = ry;
                rank[ry]++;
            }
        }
    }
private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> indexOf;
        UnionFind uf(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(indexOf.count(accounts[i][j])){
                    uf.connect(i, indexOf[accounts[i][j]]);
                }
                else{
                    indexOf[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, vector<string>> temp;
        for(auto& [email, index] : indexOf){
            temp[uf.find(index)].push_back(email);
        }
        vector<vector<string>> res;
        for(auto& [i, emails] : temp){
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[i][0]);
            res.push_back(emails);
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<string>> accounts;
    vector<vector<string>> res;

    accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"}
               ,{"John","johnsmith@mail.com","john00@mail.com"}
               ,{"Mary","mary@mail.com"}
               ,{"John","johnnybravo@mail.com"}};
    res = solution.accountsMerge(accounts);
    print2DVector(res);

    accounts = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"}
               ,{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"}
               ,{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"}
               ,{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"}
               ,{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    res = solution.accountsMerge(accounts);
    print2DVector(res);
    return 0;
}