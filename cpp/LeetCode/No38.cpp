/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1)
, which is then converted into a different digit string.
To determine how you "say" a digit string
, split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
Then for each substring, say the number of digits, then say the digit. 
Finally, concatenate every said digit.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string temp = countAndSay(n-1);
        int count = 1;
        string res = "";
        for(int i=1;i<temp.size();i++){
            if(temp[i]==temp[i-1]){
                count++;
            }
            else{
                res+=(to_string(count)+temp[i-1]);
                count = 1;
            }
        }
        res+=(to_string(count)+temp.back());
        return res;
    }
};

int main(){
    Solution solution;
    
    cout << solution.countAndSay(5) << endl;
    return 0;
}
