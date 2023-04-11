/*
You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        double res = 1;
        if(target==n){
            for(int i=0;i<n;i++){
                res*=prob[i];
            }
            return res;
        }
        else if(target==0){
            for(int i=0;i<n;i++){
                res*=(1.0-prob[i]);
            }
            return res;
        }

        vector<vector<double>> mem(n, vector<double>(target+1, -1.0));
        res = dp(prob, target, 0, mem);
        return res;
    }
private:
    double dp(vector<double>& prob, int target, int index, vector<vector<double>>& mem){
        if(index==prob.size()){
            if(target==0) return 1;
            else return 0;
        }
        if(target==0){
            double res = 1;
            for(int i=index;i<prob.size();i++){
                res*=(1.0-prob[i]);
            }
            return mem[index][target] = res;
        }
        if(mem[index][target]!=-1.0) return mem[index][target];

        double res = 0;
        if(target>0){
            double head = prob[index] * dp(prob, target-1, index+1, mem);
            double tail = (1.0-prob[index]) * dp(prob, target, index+1, mem);
            res = head+tail;
        }
        else{
            res = (1.0-prob[index]) * dp(prob, target, index+1, mem);
        }
        return mem[index][target] = res;
    }
};

int main(void){
    Solution solution;
    vector<double> prob;
    int target;

    prob = {0.4};
    target = 1;
    cout << solution.probabilityOfHeads(prob, target) << endl;

    prob = {0.5,0.5,0.5,0.5,0.5};
    target = 0;
    cout << solution.probabilityOfHeads(prob, target) << endl;
    return 0;
}