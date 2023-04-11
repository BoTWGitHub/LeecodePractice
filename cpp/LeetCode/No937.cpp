/*
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.
*/
#include <iostream>
#include <algorithm>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let;
        vector<string> dig;
        for(string s : logs){
            int p = s.find_first_of(' ')+1;
            if(isdigit(s[p])) dig.push_back(s);
            else let.push_back(s);
        }

        sort(let.begin(), let.end(), comp);
        let.insert(let.end(), dig.begin(), dig.end());
        return let;
    }
private:
    static bool comp(const string s1, const string s2){
        int p1 = s1.find_first_of(' ')+1;
        int p2 = s2.find_first_of(' ')+1;

        while(p1<s1.size() && p2<s2.size()){
            if(s1[p1]!=s2[p2]) return s1[p1]<s2[p2];
            p1++;
            p2++;
        }
        if(p1<s1.size()) return false;
        if(p2<s2.size()) return true;

        p1 = 0;
        p2 = 0;
        while(s1[p1]!=' ' && s2[p2]!=' '){
            if(s1[p1]!=s2[p2]) return s1[p1]<s2[p2];
            p1++;
            p2++;
        }
        if(s1[p1]!=' ') return false;
        return true;
    }
};

int main(void){
    Solution solution;

    vector<string> logs = {"zoey i love you","lucas i love you","rong i love you"};
    vector<string> res = solution.reorderLogFiles(logs);
    printVector(res);
    return 0;
}