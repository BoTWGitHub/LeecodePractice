/*
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. 
The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas
, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> group[26];
        for(string& i : ideas){
            group[i[0]-'a'].insert(i.substr(1));
        }
        long long res = 0;
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                int mutual = 0;
                for(string s : group[i]){
                    if(group[j].count(s)){
                        mutual++;
                    }
                }
                res+=(2*(group[i].size()-mutual)*(group[j].size()-mutual));
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<string> ideas;

    ideas = {"coffee","donuts","time","toffee"};
    cout << solution.distinctNames(ideas) << endl;

    ideas = {"lack","back"};
    cout << solution.distinctNames(ideas) << endl;
    return 0;
}