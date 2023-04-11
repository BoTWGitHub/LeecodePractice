#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> mem;
        for(string word : words){
            mem.insert(strToMorse(word));
        }
        return mem.size();
    }
private:
    vector<string> morseTable = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string strToMorse(string word){
        string res = "";
        for(char c : word){
            res.append(morseTable[c-'a']);
        }
        return res;
    }
};

int main(void){
    vector<string> words = {"gin","zen","gig","msg"};
    Solution solution;
    cout << solution.uniqueMorseRepresentations(words) << endl;
    return 0;
}