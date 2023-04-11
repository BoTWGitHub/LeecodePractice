/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%)
, and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        prefix.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            prefix.push_back(w[i]+prefix.back());
        }
    }
    
    int pickIndex() {
        int num = rand()%prefix.back()+1;
        int left = 0, right = prefix.size()-1;
        while(left<right){
            int mid = (right-left)/2+left;
            if(prefix[mid]<num) left = mid+1;
            else right = mid;
        }
        return left;
    }
private:
    vector<int> prefix;
};

int main(void){
    vector<int> w = {1,3};
    Solution solution(w);
    vector<int> freq(w.size(), 0);
    int times = 1000;
    for(int i=0;i<times;i++){
        freq[solution.pickIndex()]++;
    }
    for(int i=0;i<freq.size();i++){
        cout << "index " << i << " : " << (float)freq[i]/times << endl;
    }
    
    return 0;
}