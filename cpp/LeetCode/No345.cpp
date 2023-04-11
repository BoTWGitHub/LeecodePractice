#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vow = "";
        for(char c : s){
            if(isVowel(c)) vow+=c;
        }
        int index = vow.size()-1;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) s[i] = vow[index--];
        }
        return s;
    }
private:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
};

int main(){
    Solution solution;
    string s;

    s = "hello";
    cout << solution.reverseVowels(s) << endl;

    s = "leetcode";
    cout << solution.reverseVowels(s) << endl;

    return 0;
}