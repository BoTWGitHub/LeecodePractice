/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(string word : words) count[word]++;

        vector<pair<int, string>> list;
        vector<string> res;
        
        for(pair<string, int> element : count) list.push_back({-element.second, element.first});
        make_heap(list.begin(), list.end(), greater<pair<int, string>>());

        for(int i=0;i<k;i++){
            pop_heap(list.begin(), list.end(), greater<pair<int, string>>());
            res.push_back(list.back().second);
            list.pop_back();
        }

        return res;
    }
};

int main(){
    Solution solution;

    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> res = solution.topKFrequent(words, k);
    printVector(res);

    words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    k = 4;
    res = solution.topKFrequent(words, k);
    printVector(res);
    return 0;
}
