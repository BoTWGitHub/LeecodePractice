/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> seen;
        queue<string> q;
        q.push(start);
        seen.insert(start);
        int res = 0;
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0;i<size;i++){
                string node = q.front();
                q.pop();
                for(string s : bank){
                    if(seen.count(s)==0 && isMutate(node, s)){
                        if(s==end) return res;
                        q.push(s);
                        seen.insert(s);
                    }
                }
            }
        }
        return -1;
    }
private:
    int mutateDistance(string start, string end){
        int count = 0;
        for(int i=0;i<start.size();i++){
            if(start[i]!=end[i]){
                count++;
            }
        }
        return count;
    }
    bool isMutate(string start, string end){
        int count = 0;
        for(int i=0;i<start.size();i++){
            if(start[i]!=end[i]){
                count++;
                if(count>1) return false;
            }
        }
        return count==1;
    }
};

int main(void){
    Solution solution;
    string start;
    string end;
    vector<string> bank;

    start = "AACCGGTT";
    end = "AACCGGTA";
    bank = {"AACCGGTA"};
    cout << solution.minMutation(start, end, bank) << endl;

    start = "AACCGGTT";
    end = "AAACGGTA";
    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout << solution.minMutation(start, end, bank) << endl;

    start = "AAAAACCC";
    end = "AACCCCCC";
    bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    cout << solution.minMutation(start, end, bank) << endl;

    start = "AACCGGTT";
    end = "AAACGGTA";
    bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    cout << solution.minMutation(start, end, bank) << endl;

    return 0;
}