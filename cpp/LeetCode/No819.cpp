/*
Given a string paragraph and a string array of the banned words banned
, return the most frequent word that is not banned. 
It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> counter;
        int index = 0;
        int maxCount = 0;
        string res = "";
        while(index<paragraph.size()){
            while(index<paragraph.size() && notLetter(paragraph[index])) index++;
            string temp;
            while(index<paragraph.size() && !notLetter(paragraph[index])){
                if(paragraph[index]>='A' && paragraph[index]<='Z'){
                    temp.push_back(paragraph[index]-'A'+'a');
                }
                else{
                    temp.push_back(paragraph[index]);
                }
                index++;
            }
            if(ban.count(temp)==0){
                counter[temp]++;
                if(counter[temp]>maxCount){
                    maxCount = counter[temp];
                    res = temp;
                }
            }
        }
        return res;
    }
private:
    bool notLetter(char c){
        return (c==' ' || c=='!' || c=='?' || c=='\'' || c==';' || c==',' || c=='.' || c=='\"');
    }
};

int main(void){
    Solution solution;
    string paragraph;
    vector<string> banned;

    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    banned = {"hit"};
    cout << solution.mostCommonWord(paragraph, banned) << endl;

    paragraph = "a";
    banned = {};
    cout << solution.mostCommonWord(paragraph, banned) << endl;
    return 0;
}