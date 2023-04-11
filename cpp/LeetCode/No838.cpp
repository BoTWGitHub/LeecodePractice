/*
There are n dominoes in a line, and we place each domino vertically upright. 
In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. 
Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        vector<int> force = vector<int>(len);
        int f = 0;
        for(int i=0;i<len;i++){
            if(dominoes[i]=='R') f = len;
            else if(dominoes[i]=='L') f = 0;
            else f = f>0?f-1:f;
            force[i] = f;
        }
        for(int i=len-1;i>=0;i--){
            if(dominoes[i]=='R') f = 0;
            else if(dominoes[i]=='L') f = len;
            else f = f>0?f-1:f;
            force[i] -= f;
        }
        for(int i=0;i<len;i++){
            if(force[i]==0) dominoes[i] = '.';
            else if(force[i]<0) dominoes[i] = 'L';
            else dominoes[i] = 'R';
        }
        return dominoes;
    }
};

int main(){
    Solution solution;

    string dominoes = ".R..L.";
    cout << solution.pushDominoes(dominoes) << endl;
    return 0;
}
