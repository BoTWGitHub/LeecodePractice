/*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. 
You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. 
If you cut the pizza vertically, give the left part of the pizza to a person. 
If you cut the pizza horizontally, give the upper part of the pizza to a person. 
Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. 
Since the answer can be a huge number, return this modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>> prefix(pizza.size(), vector<int>(pizza[0].size(), 0));
        for(int i=0;i<pizza.size();i++){
            for(int j=0;j<pizza[0].size();j++){
                int temp = pizza[i][j]=='A';
                if(i>0) temp+=prefix[i-1][j];
                if(j>0) temp+=prefix[i][j-1];
                if(i>0 && j>0) temp-=prefix[i-1][j-1];
                prefix[i][j] = temp;
            }
        }
        vector<vector<vector<int>>> mem(k+1, vector<vector<int>>(pizza.size(), vector<int>(pizza[0].size(), -1)));
        return dp(prefix, k, 0, 0, mem);
    }
private:
    const int mod = 1e9+7;
    int dp(vector<vector<int>>& prefix, int k, int r, int c, vector<vector<vector<int>>>& mem){
        if(k==1){
            int s = prefix.back().back();
            if(r>0) s-=prefix[r-1].back();
            if(c>0) s-=prefix.back()[c-1];
            if(r>0 && c>0) s+=prefix[r-1][c-1];
            return s>0;
        }
        if(mem[k][r][c]!=-1) return mem[k][r][c];

        int res = 0;

        //cut vertical
        bool hasApple = false;
        for(int i=c;i<prefix[0].size()-1;i++){
            if(!hasApple){
                int s = prefix.back()[i];
                if(r>0) s-=prefix[r-1][i];
                if(c>0) s-=prefix.back()[c-1];
                if(r>0 && c>0) s+=prefix[r-1][c-1];
                if(s>0) hasApple = true;
            }
            if(hasApple) res = (res+dp(prefix, k-1, r, i+1, mem))%mod;
        }

        //cut horizontal
        hasApple = false;
        for(int i=r;i<prefix.size()-1;i++){
            if(!hasApple){
                int s = prefix[i].back();
                if(r>0) s-=prefix[r-1].back();
                if(c>0) s-=prefix[i][c-1];
                if(r>0 && c>0) s+=prefix[r-1][c-1];
                if(s>0) hasApple = true;
            }
            if(hasApple) res = (res+dp(prefix, k-1, i+1, c, mem))%mod;
        }

        return mem[k][r][c] = res;
    }
};

int main(void){
    Solution solution;
    vector<string> pizza;
    int k;

    pizza = {"A..","AAA","..."};
    k = 3;
    cout << solution.ways(pizza, k) << endl;

    pizza = {"A..","AA.","..."};
    k = 3;
    cout << solution.ways(pizza, k) << endl;

    pizza = {"A..","A..","..."};
    k = 1;
    cout << solution.ways(pizza, k) << endl;
    return 0;
}