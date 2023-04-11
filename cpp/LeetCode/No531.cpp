/*
Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, vector<int>> row_map;
        for(int i=0;i<picture.size();i++) row_map[i] = vector<int>();
        vector<int> col_count = vector<int>(picture[0].size(), 0);

        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[0].size();j++){
                if(picture[i][j]=='B'){
                    row_map[i].push_back(j);
                    col_count[j]++;
                }
            }
        }

        int res = 0;
        for(unordered_map<int, vector<int>>::iterator it=row_map.begin();it!=row_map.end();it++){
            if(it->second.size()==1 && col_count[it->second[0]]==1){
                res++;
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    
    vector<vector<char>> picture = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
    cout << solution.findLonelyPixel(picture) << endl;
    unordered_map<int, vector<int>> temp;
    return 0;
}